#include <iostream>
#include <fstream>
#include "p2set.h"
using namespace std;

int main()
{
	//declare variables
	ifstream finOld, finNew;
	int dues = 80, memberDues = 62, size;
	int oldMemberDues = 0, newMemberDues = 0, totalMembers = 0;
	string name, junk;
	Set<string> s;
	
	//initialize data structures and open files
	finOld.open("8A_past.txt");
	finNew.open("8A_new.txt");
	initialize(s);
	
	//check to make sure files opened
	if (finOld.is_open() && finNew.is_open())
	{
		//get membership roll from past file and white space before \n
		finOld >> junk >> junk >> size;
		getline(finOld, junk);
		
		//go through file until membership roll value has been reached
		for (int i = 0; i < size; i++)
		{
			getline(finOld, name);
			insert(s, name);
			totalMembers++;
		}
		
		//get membership roll from new file and white space before \n
		finNew >> junk >> junk >> size;
		getline(finNew, junk);
		
		//go through file until membership roll value has been reached
		for (int i = 0; i < size; i++)
		{
			getline(finNew, name);
			
			//if not an old member, they pay new member dues and
			//adds to the amount of members over 2 years
			//if they are an old member they pay old member dues
			if (!contains(s, name))
			{
				newMemberDues++;
				totalMembers++;
			}
			else
				oldMemberDues++;
		}
		
		//multiply the amount of people for each by the price they pay
		newMemberDues *= dues;
		oldMemberDues *= memberDues;
	
		//output the resulting values
		cout << "Old Member Dues: $" << oldMemberDues
			 << "\nNew Member Dues: $" << newMemberDues
			 << "\nTotal expected:  $" << oldMemberDues + newMemberDues
			 << "\n\nTwo-year membership: " << totalMembers;
			 
		//destroy data structures and close files
		destroy(s);
		finOld.close();
		finNew.close();
	}
	
	//tell user if files did not open
	else
		cout << "Files did not open";
}
