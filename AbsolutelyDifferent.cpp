#include <iostream>
#include <sstream>
using namespace std;

//takes difference of two numbers and returns abval of them
int abvalOfDifference (int a, int b)
{
	//declare variable
	int result;
	
	//subtract the two integers given
	result = a - b;
	
	//take the absolute value of that difference
	if (result < 0)
		result *= -1;
	
	return result;
}

//decides if the given sequence is good
//if sequence is not good, returns smallest missing number
int sequence (int list[], int size)
{
	//declare variables
	int count = 1, i = 0;
	bool missing = true;
	
	//outer loop contains count which goes up until it is size-1
	while (count < size)
	{
		//inner loop looks for count in list
		while(i < size)
		{
			//if found, inner loop breaks because there is no reason to keep looping
			if (list[i] == count)
			{
				missing = false;
				break;
			}
			
			i++;
		}
		
		//if inner loop never breaks it finds the missing number which
		//is also the smallest since count is incrementing from 1
		if (missing == true)
			return count;
		
		//increment count and reset variables
		count++;
		missing = true;
		i = 0;
	}
	
	//if it makes it all the way through the outer loop without returning then
	//there are no missing values and it is a good sequence
	return 0;
}

int main()
{
	//declare variables
	string line = "";
	int numbers[1000] = {0}, results[1000] = {0}, i = 0, j = 0, size = 0, number;
	
	//prompt user for input
	cout << "Enter list: ";
	
	//get input line and save it to line
	//start string stream with line
	getline(cin, line);
	stringstream ss(line);
	
	//convert line in the ss into integers and places it in results array
	while (ss >> number)
	{
		numbers[j] = number;
		j++;
	}

	//get size of numbers array and initialize j again
	size = j;
	j = 0;
	
	//find abval of difference between adjacent numbers
	//and place the number into the results array
	while (numbers[i+1] != 0)
	{
		results[i] = abvalOfDifference(numbers[i], numbers[i+1]);
		i++;
	}

	//figure out if it is a good sequence or not
	int missing = sequence(results, size);
	
	if (missing == 0)
		cout << "Good sequence.";
	else
		cout << "Bad sequence: missing " << missing << ".";
}
