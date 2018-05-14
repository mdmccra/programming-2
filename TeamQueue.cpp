#include <iostream>
#include <fstream>
#include <sstream>
#include "p2map.h"
#include "p2queue.h"
using namespace std;

int main ()
{
	//declare variables
	ifstream fin;
	ofstream fout;
	string line, name, junk, input[1000] = "";
	int count = 0, size, team, team2;
	Map<string,int> m;
	Queue<string> q;
	
	//initialize data structures and open files
	initialize(m);
	initialize(q);
	
	//testing files
//	fin.open("teams.txt");
//	fout.open("grouped.txt");

	//athene files
	fin.open("teams");
	fout.open("grouped");
	
	//make sure files opened
	if (fin.is_open() && fout.is_open())
	{
		//get amount of teams
		fin >> size;
		getline(fin, junk);
		
		//put members and team number into map
		for (int i = 0; i < size; i++)
		{
			getline(fin, line);
			stringstream ss(line);
			
			while (ss >> name)
			{
				assign(m, name, i);
			}
		}
		
		//put inputted names into array
		cin >> name;
		while (name != "END")
		{
			input[count] = name;
			count++;
			cin >> name;
		}
		
		//goes through array
		for (int i = 0; i < count; i++)
		{
			//sets first team number
			if (has_key(m, input[i]))
				team = lookup(m, input[i]);
			
			//goes through array
			for (int j = 0; j < count; j++)
			{
				//sets second team number to be compared to first
				//unless it has already been removed from map
				if (has_key(m, input[j]))
				{
					team2 = lookup(m, input[j]);
					
					//if on same team, push name into queue and remove from map
					if (team == team2)
					{
						push(q, input[j]);
						remove(m, input[j]);
					}
				}	
			}
		}

		//output loop
		while (!isEmpty(q))
			fout << pop(q) << endl;
		
		//destroy data structures and close files
		destroy(m);
		destroy(q);
		fin.close();
		fout.close();
	}
	
	//tell user files did not open if they did not open
	else
		cout << "files did not open";
}
