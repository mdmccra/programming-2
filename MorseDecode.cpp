#include <iostream>
#include <sstream>
using namespace std;

//figures out which letter corresponds to the code entered
char morseToLetter (string code)
{
	if (code == ".-")
		return 'A';
	else if (code == "-...")
		return 'B';
	else if (code == "-.-.")
		return 'C';
	else if (code == "-..")
		return 'D';
	else if (code == ".")
		return 'E';
	else if (code == "..-.")
		return 'F';
	else if (code == "--.")
		return 'G';
	else if (code == "....")
		return 'H';
	else if (code == "..")
		return 'I';
	else if (code == ".---")
		return 'J';
	else if (code == "-.-")
		return 'K';
	else if (code == ".-..")
		return 'L';
	else if (code == "--")
		return 'M';
	else if (code == "-.")
		return 'N';
	else if (code == "---")
		return 'O';
	else if (code == ".--.")
		return 'P';
	else if (code == "--.-")
		return 'Q';
	else if (code == ".-.")
		return 'R';
	else if (code == "...")
		return 'S';
	else if (code == "-")
		return 'T';
	else if (code == "..-")
		return 'U';
	else if (code == "...-")
		return 'V';
	else if (code == ".--")
		return 'W';
	else if (code == "-..-")
		return 'X';
	else if (code == "-.--")
		return 'Y';
	else if (code == "--..")
		return 'Z';
	return 0;
}

int main()
{
	//declare variables
	string line, result = "", word;
	
	//prompt user for input
	cout << "Enter Morse words, one per line:" << endl;
	
	//user inputs line
	while (getline(cin, line))
	{
		//checks to see if Quit has been entered
		if (line == "Quit")
			break;
		
		//puts the entered line into the stringstream
		stringstream ss(line);
		
		//goes through each morse code word at a time and concatanates it on to the result string
		while (ss >> word)
			result += morseToLetter(word);
		
		//adds a space after each word
		result += ' ';
	}
	
	//outputs result string
	cout << endl << result;
}
