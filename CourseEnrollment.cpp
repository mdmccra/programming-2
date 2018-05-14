#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "p2priorityqueue.h"
using namespace std;

int main()
{
	//declare variables
	ifstream fin;
	ofstream fout;
	PriorityQueue<string,int> pqA;
	PriorityQueue<string,int> pqB;
	PriorityQueue<string,int> pqC;
	string line = "", input_filename = "", course = "", id = "";
	int semester = 0;
	
	//initialize Priority Queues
	initialize(pqA);
	initialize(pqB);
	initialize(pqC);
	
	//get input filename from user
	cout << "Input file: ";
	cin  >> input_filename;
	
	//open input file and intitial output file
	fin.open(input_filename.c_str());
	fout.open("CS332");

	//go through each line of the input file and insert
	//the student info into a different Priority Queue
	//depending on which course they are signing up for
	while (getline(fin,line))
	{
		stringstream ss(line);
		
		ss >> course;
		
		if (course == "CS332")
		{
			ss >> id;
			ss >> semester;
			push(pqA, id, semester);
		}
		
		else if (course == "CS352")
		{
			ss >> id;
			ss >> semester;
			push(pqB, id, semester);
		}
		
		else //course == "CS365"
		{
			ss >> id;
			ss >> semester;
			push(pqC, id, semester);
		}
	}

	//output into CS332
	while (!isEmpty(pqA))
		fout << pop(pqA) << endl;
	
	
	fout.close();
	
	//output into CS352
	fout.open("CS352");
	
	while (!isEmpty(pqB))
		fout << pop(pqB) << endl;
	
	
	fout.close();
	
	//output into CS365
	fout.open("CS365");
	
	while (!isEmpty(pqC))
		fout << pop(pqC) << endl;
	
	//destroy Priority Queues and close fstream
	destroy(pqA);
	destroy(pqB);
	destroy(pqC);
	fin.close();
	fout.close();
}
