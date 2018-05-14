#include <iostream>
#include <fstream>
#include "p2graph.h"
using namespace std;

int main()
{
	//declare variables
	ifstream fin;
	string junk;
	char relationship;
	int member1, member2, path;
	Graph<int> g;
	
	//initalize graph and open file
	initialize(g);
	fin.open("connections");
	
	//if file is opened, run program
	if (fin.is_open())
	{
		//create graph from info in file
		while (fin >> member1 >> relationship >> member2)
		{
			//add the pair of vertices into the graph
			addVertex(g, member1);
			addVertex(g, member2);
			
			//add edge between the 2 members
			if (relationship == 'o')
				addEdge(g, member1, member2, 2);
			else //relationship == 'x'
				addEdge(g, member1, member2, 1);
		}
		
		//get user input for what connection they want to search
		cout << "File read.\nWhat connection do you want to search?\n";
		cin  >> junk >> member1 >> member2;
		
		//search for relationship in graph
		//determine relationship between the 2 members and output
		//if both nodes exist
		if (hasVertex(g, member1) && hasVertex(g, member2))
		{
			path = shortestPath(g, member1, member2);
			
			if (path == 0)
				cout << "Connection unknown";
			else if (path % 2 == 0)
				cout << "Members of the same gang";
			else
				cout << "Members of different gangs";
		}
		
		else
			cout << "Connection unknown";
		
		//close file
		fin.close();	
	}
	
	//inform user if file does not open
	else
		cout << "Files did not open.";
	
	//destroy graph
	destroy(g);
	
}
