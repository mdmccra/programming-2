#include <iostream>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

//integer array with the amount of days in each month
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//integer array with the amount of days in each month on a leap year
int daysLeap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

istream& operator>>(istream& in, Date &d)
{
    //input day, /, month, /, year
    char c;
    in >> d.month >> c >> d.day >> c >> d.year;
    return in;
}

ostream& operator<<(ostream& out, Date d)
{
    //output day, /, month, /, year
    out << d.month << '/' << d.day << '/' << d.year;
    return out;
}

bool operator<(Date a, Date b)
{
	//if year is lesser returns true
	//if years are equal and month is lesser returns true
	//if year and month are equal and day is lesser returns true
	//otherwise returns false
	if (a.year < b.year)
		return true;
	else if (a.year == b.year && a.month < b.month)
		return true;
	else if (a.year == b.year && a.month == b.month && a.day < b.day)
		return true;
	else
		return false;
}

bool operator>(Date a, Date b)
{
	//if year is greater returns true
	//if years are equal and month is greater returns true
	//if year and month are equal and day is greater returns true
	//otherwise returns false
	if (a.year > b.year)
		return true;
	else if (a.year == b.year && a.month > b.month)
		return true;
	else if (a.year == b.year && a.month == b.month && a.day > b.day)
		return true;
	else
		return false;
}

bool operator==(Date a, Date b)
{
	//checks each part of the struct Date to see if it is equal
	if (a.year == b.year && a.month == b.month && a.day == b.day)
		return true;
	else
		return false;
}

bool operator<=(Date a, Date b)
{
	//if a and b are not equal or a is not less than b, returns false
	if (a == b)
		return true;
	else if (a < b)
		return true;
	else
		return false;
}

bool operator>=(Date a, Date b)
{
	//if a and b are not equal or a is not greater than b, returns false
	if (a == b)
		return true;
	else if (a > b)
		return true;
	else
		return false;
}

Date operator+(Date a, int i)
{
	//add the integer onto day
	a.day += i;
	
	//if it is a leap year
	if (a.year % 4 == 0 && (a.year % 100 != 0 || a.year % 400 == 0))
	{
		//while days are greater than amount of days in that month
		while (a.day > daysLeap[a.month - 1])
		{
			//subtract number of days in that month
			a.day -= daysLeap[a.month - 1];
			
			//add a counter for month
			a.month++;
			
			//add to year if month goes past December
			if (a.month > 12)
			{
				a.month = 1;
				a.year++;
			}
		}
	}
	
	//if it is not a leap year
	else
	{	
		//while days are greater than amount of days in that month
		while (a.day > days[a.month - 1])
		{
			//subtract number of days in that month
			a.day -= days[a.month -1];
			
			//add a counter for month
			a.month++;
			
			//add to year if month goes past December
			if (a.month > 12)
			{
				a.month = 1;
				a.year++;
			}
		}
	}
	
	//return Date a which is the original plus days, i
	return a;
}

Date getTomorrow(Date a)
{
	//tomorrow is just the date plus one date, so this uses the
	//operator+ function to return the date plus one day
	return a + 1;
}
