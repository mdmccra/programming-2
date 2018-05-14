#include <iostream>
#include <sstream>
#include "p2priorityqueue.h"
#include "p2set.h"
using namespace std;

int main()
{
	//declare variables
	string line;
	int value, k, factors[10] = {0}, i = 0;	
	PriorityQueue<int,int> pq;
	Set<int> s;
	
	//initialize ADT's
	initialize(pq);
	initialize(s);

	//get user input
	cout << "Prime factors: ";
	getline(cin, line);
	
	cout << "K: ";
	cin >> k;
	
	//put prime factors into integer array
	stringstream ss(line);
	while (ss >> factors[i])
		i++;
	
	//push values into pq and set
	//set is used to avoid creating duplicates in the pq
	value = 1;
	push(pq, value, value * -1);
	
	while (k > 0)
	{
		for (int j = 0; j < i; j++)
			if (!contains(s, value * factors[j]))
			{
				push(pq, value * factors[j], value * factors[j] * -1);
				insert(s, value * factors[j]);
			}
		
		//last value popped is the kth value
		if (!isEmpty(pq))			
			value = pop(pq);
		k--;
	}
	
	//output result
	cout << endl << "Result: " << value;

	//destroy ADT's
	destroy(pq);
	destroy(s);
}
