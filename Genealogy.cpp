#include <iostream>
#include <fstream>
#include <string>
#include "p2map.h"
using namespace std;

int main()
{
	//declare variables
	ifstream fin;
	ofstream fout;
	string input_filename, father, son, name;
	Map<string, string> fs;
	Map<string, string> sf;

	//initialize maps
	initialize(fs);
	initialize(sf);
	
	//get input filename and output filename from user and open them
	cout << "Input file: ";
	cin  >> input_filename;
	fin.open(input_filename.c_str());
	
	input_filename = "fixed_" + input_filename;
	fout.open(input_filename.c_str());
	
	if(fin.is_open() && fout.is_open())
	{
		//insert everything from the file into both maps
		while (fin >> father >> son)
		{
			assign(fs, father, son);
			assign(sf, son, father);
		}
		
		//goes through map until there is no key
		//the name with no key is the eldest father
		name = son;
		while (has_key(sf, name))
			name = lookup(sf, name);
		
		//fout the name of the father then the son while there is a key for the name
		while(has_key(fs, name))
		{
			fout << name << " " << lookup(fs, name) << endl;
			name = lookup(fs, name);
		}		
		
		cout << "Ordering complete.";
	}
	
	else
		cout << "At least one file did not open.";
	
	//destroy maps and close fstream
	destroy(fs);
	destroy(sf);
	fin.close();
	fout.close();
}
