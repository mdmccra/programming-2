#include <iostream>
#include "p2queue.h"
#include "p2priorityqueue.h"
#include "p2stack.h"
using namespace std;

int main()
{
	//declare variables
	string command;
	int value, Qvalue, Svalue, PQvalue;
	bool isQ = true, isPQ = true, isS = true;
	Queue<int> q;
	Stack<int> s;
	PriorityQueue<int,int> pq;
	
	//initialize the ADT's before use
	initialize(q);
	initialize(s);
	initialize(pq);
	
	//read in user input and place push in the in array, place
	//pop in the out array, and place commands in the commands array
	cout << "Command: ";
	cin >> command >> value;
	
	while (command != "END")
	{	
		if (command == "PUSH")
		{	
			//push value into the ADT's
			push(q, value);
			push(s, value);
			push(pq, value, value);
		}	
		else //command == "POP"
		{
			//assign the popped value
			if (!isEmpty(q) && !isEmpty(pq) && !isEmpty(s))
			{
				Qvalue = pop(q);
				Svalue = pop(s);
				PQvalue = pop(pq);
			}
			
			//if ADT does not equal the value that it is supposed to sets to false
			if (Qvalue != value && isQ)
				isQ = false;

			if (Svalue != value && isS)
				isS = false;

			if (PQvalue != value && isPQ)
				isPQ = false;
		}
		
		//prompt user for input
		cout << "Command: ";
		cin >> command >> value;
	}
	
	//output what the black box holds based on which statements remain true
	if ((isQ && isS) || (isQ && isPQ) || (isS && isPQ) || (isQ && isS && isPQ))
		cout << "The black box remains mysterious." << endl;
	else if (isQ)
		cout << "The black box holds a queue." << endl;
	else if (isS)
		cout << "The black box holds a stack." << endl;
	else if (isPQ)
		cout << "The black box holds a priority queue." << endl;
	else
		cout << "The black box holds something else." << endl;
		
	//destroy ADT's when finished
	destroy(q);
	destroy(s);
	destroy(pq);	
}
