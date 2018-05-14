#include <iostream>
#include <fstream>
#include "p2queue.h"
//#include "p2queue4.h"
using namespace std;

//returns an int value so that values may be compared
int conversion(string s)
{
	if (s == "J")
		return 11;
	else if (s == "Q")
		return 12;
	else if (s == "K")
		return 13;
	else if (s == "A")
		return 14;
	else if (s == "10")
		return 10;
	return (int) s[0] - 48;
}

int main()
{
	//declare variables
	ifstream finP1, finP2;
	string s;
	int battles = 0, card, p1card, p2card;
	Queue<int> p1;
	Queue<int> p2;
	Queue<int> p1tie;
	Queue<int> p2tie;
	
	//initialize data structures and open files
	initialize(p1);
	initialize(p2);
	initialize(p1tie);
	initialize(p2tie);
	
	finP1.open("player1");
//	finP1.open("1.txt");
	finP2.open("player2");
//	finP2.open("2.txt");	
	//check to make sure files opened
	if (finP1.is_open() && finP2.is_open())
	{
		//push everyting into the p1 queue from the p1 file
		while (finP1 >> s)
		{
			card = conversion(s);
			push(p1, card);
		}		
		
		//push everyting into the p2 queue from the p2 file
		while (finP2 >> s)
		{
			card = conversion(s);
			push(p2, card);
		}
		
		//loops until a player loses or battles reaches a number greater than 5000
		while ((!isEmpty(p1)) && (!isEmpty(p2)) && battles < 5000)
		{
			p1card = pop(p1);
			p2card = pop(p2);
			
			//player 1 wins
			if (p1card > p2card)
			{
				//check if this is a tie deciding battle
				if (!isEmpty(p1tie))
				{
					while (!isEmpty(p1tie))
						push(p1, pop(p1tie));
						
					push(p1, p1card);
					
					while (!isEmpty(p2tie))
						push(p1, pop(p2tie));
						
					push(p1, p2card);
				}

				//otherwise just push into the winners hand
				else
				{
					push(p1, p1card);
					push(p1, p2card);
				}
			}
			
			//player 2 wins
			else if (p2card > p1card)
			{
				//check if this is a tie deciding battle
				if (!isEmpty(p2tie))
				{
					while (!isEmpty(p2tie))
					{
						push(p2, pop(p2tie));
					}
					push(p2, p2card);
					
					while (!isEmpty(p1tie))
					{
						push(p2, pop(p1tie));
					}
					push(p2, p1card);
				}
				
				//otherwise just push into the winners hand
				else
				{
					push(p2, p2card);
					push(p2, p1card);
				}
			}
			
			//it is a tie
			else 
			{
				push(p1tie, p1card);
				push(p2tie, p2card);
				
				//place 3 cards from each players hand into their tie queue
				for (int i = 0; i < 3; i++)
					if (!isEmpty(p1))
						push(p1tie, pop(p1));
				
				for (int i = 0; i < 3; i++)
					if (!isEmpty(p2))
						push(p2tie, pop(p2));
			}
			
			//increment battle count
			battles++;
		}
		
		//output who won
		if (isEmpty(p2))
			cout << "Player 1 wins after " << battles << " battles.";
		else if (isEmpty(p1))
			cout << "Player 2 wins after " << battles << " battles.";
		else //battle max reached
			cout << "Nobody wins.";
		
		//destroy data structures and close files
		destroy(p1);
		destroy(p2);
		destroy(p1tie);
		destroy(p2tie);
		finP1.close();
		finP2.close();
	}
	
	//tell user if files did not open
	else
		cout << "Files did not open";
}
