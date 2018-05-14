#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "p2priorityqueue.h"
#include "p2map.h"
using namespace std;

int main()
{
	//declare variables
	ifstream finName, finVote;
	string input_filename, lineName, lineVote, name;
	Map<int, int> mPhone;
	Map<string, int> mVotes;
	PriorityQueue<string, int> pq;
	int totalVotes, votesUsed = 0, contestants, votes = 0, number, i = 0;
	
	//initialize the maps and priority Queue
	initialize (mVotes);
	initialize (mPhone);
	initialize (pq);
	
	//get input filenames from user and open them
	cout << "Enter filename containing list of contestants: ";
	cin  >> input_filename;
	finName.open(input_filename.c_str());

	cout << "Enter filename containing list of votes: ";
	cin  >> input_filename;
	finVote.open(input_filename.c_str());

	if (finName.is_open() && finVote.is_open())
	{
		//read in number of contestants and number of votes from input file
		finName >> contestants;
		finVote >> totalVotes;
		
		//go through the votes file, get the name and number, insert them into the name
		//and number maps if the number has voted less than 4 times
		while (i < totalVotes)
		{
			finVote >> name >> number;
			
			if (!has_key(mPhone, number))
				assign(mPhone, number, 0);
				
			if (!has_key(mVotes, name))
				assign(mVotes, name, 0);
				
			//uses the map functionality to make the value be a count variable while
			//still holding the same key
			if (lookup(mPhone, number) < 4)
			{
				assign(mPhone, number, lookup(mPhone, number) + 1);
				assign(mVotes, name, lookup(mVotes, name) + 1);
				votesUsed++;
			}
			
			//increment loop count variable
			i++;
		}
		//reset loop count variable
		i = 0;
		
		//inserts names of the contestants into priority queue with number of votes
		//gets the names from the names file
		//if contestant does not recieve any votes, assigns 0 to that name in the map
		while (i < contestants)
		{
			finName >> name;
			
			if (!has_key(mVotes, name))
				assign(mVotes, name, 0);
				
			push(pq, name, lookup(mVotes, name));
			i++;
		}
		
		//output end ranking results
		cout << endl << "Final rankings" << endl	
		     << fixed << setprecision(1);
		
		while (!isEmpty(pq))
		{
			name = pop(pq);
			cout << ((float) lookup(mVotes, name) / votesUsed) * 100 << "% " << name << endl;
		}
		
		//close the files and destroy the maps and priority queue
		finName.close();
		finVote.close();
		destroy (mVotes);
		destroy (mPhone);
		destroy (pq);
	}
	else
		cout << "Files did not open.";
}
