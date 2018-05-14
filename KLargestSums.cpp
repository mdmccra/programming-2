#include <iostream>
#include <sstream>
#include "p2priorityqueue.h"
using namespace std;

int main()
{
	//declare variables
	int listA[1000] = {0}, listB[1000] = {0}, k = 0, a = 0, b = 0, number = 0;
	string lineA = "", lineB = "";
	PriorityQueue<int,int> pq;
	
	//intialize the Priority Queue
	initialize(pq);
	
	//get user input
	cout << "Enter 1st list: ";
	getline(cin,lineA);
	
	cout << "Enter 2nd list: ";
	getline(cin,lineB);
	
	cout << "Enter k: ";
	cin  >> k;
	
	cout << endl << k << " largest sums\n";
	
	//use stringstream to convert to integers
	stringstream ssa(lineA);
	
	while (ssa >> number)
	{
		listA[a] = number;
		a++;
	}
	a = 0;
	
	stringstream ssb(lineB);
	
	while (ssb >> number)
	{
		listB[b] = number;
		b++;
	}
	b = 0;
	
	//use nested loops to add together the different possible sums
	//and add them to the priority queue with the priority number
	//being the sum
	while (listA[a] != 0)
	{
		while (listB[b] != 0)
		{
			push(pq, listA[a] + listB[b], listA[a] + listB[b]);	
			b++;
		}
		a++;
		b = 0;
	}
	
	//output the largest sums from the Priority Queue
	while (!isEmpty(pq) && k > 0)
	{
		cout << pop(pq) << endl;
		k--;
	}
	
	//destroy the Priority Queue when finished with it
	destroy(pq);
}
