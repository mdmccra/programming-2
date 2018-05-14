#include <iostream>
#include "p2stack.h"
using namespace std;

bool wellFormed (string line)
{
	//declare variables
	Stack<char> s;
	
	//initialize the stack before using it
	initialize(s);
	
	//cannot begin with a closing symbol
	if (line[0] == ')' || line[0] == ']')
	{
		destroy(s);
		return false;
	}

	//goes through line and looks at each symbol
	for (int i = 0; line[i] != 0; i++)
	{
		//pushes on to the stack if it is an opening symbol
		if (line[i] == '(' || line[i] == '[')
			push(s,line[i]);
		
		//if closing parenthesis, checks for opening parenthesis
		else if (line[i] == ')')
		{
			if (isEmpty(s))
			{
				destroy(s);
				return false;
			}
			
			if (pop(s) != '(')
			{
				destroy(s);	
				return false;
			}
		}
		
		//if closing bracket, checks for opening bracket
		else //line[i] == ']'
		{
			if (isEmpty(s))
			{
				destroy(s);
				return false;
			}
			
			if (pop(s) != '[')
			{
				destroy(s);
				return false;
			}
		}
	}
	
	//if the stack is still populated then there is an unmatched symbol
	if (!isEmpty(s))
	{
		destroy(s);
		return false;
	}
		
	//destroy the stack when finished using it
	destroy(s);
	
	return true;
}

int main()
{
	//declare variables
	string line = "";

	//get user input
	getline(cin, line);
		
	//if wellFormed does not return false throughout the loop
	//then the line is considered to be well formed
	if (wellFormed(line))
		cout << "Expression " << line << " is well-formed.";
	else
		cout << "Expression " << line << " is not well-formed.";
}
