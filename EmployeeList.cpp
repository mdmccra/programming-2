#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Insertion sort function used to sort ID numbers of the employees
void sort (string A[])
{
	for (int i = 1; A[i] != ""; i++)
    {
		int pos = i;
        string value = A[pos];
        while (pos > 0 && value < A[pos-1]) 
        {
            A[pos] = A[pos-1];
            pos--;
        }
        A[pos] = value;
	}
}

int main()
{
	//declare variables
	ifstream fin;
	ofstream fout;
	string input_filename, output_filename, employees[1000] = "", firstName, lastName, id;
	
	//get filenames from user
	cout << "Input file: ";
	cin  >> input_filename;
	cout << "Output file: ";
	cin  >> output_filename;
	
	//open input and output files
	fin.open(input_filename.c_str());
	fout.open(output_filename.c_str());
	
	//put employees from input_filename into the employees string array
	//and change the order to ID#, First Name, Last Name
	int i = 0;
	while (fin >> firstName >> lastName >> id)
	{
		employees[i] = employees[i] + id + (char)32 + firstName + (char)32 + lastName;
		i++;
	}
	
	//sort employees from the employees string array
	sort(employees);
	
	//output sorted employee list to output_filename
	for (i = 0; employees[i] != ""; i++)
		fout << employees[i] << endl;
	
	//close input and output files
	fin.close();
	fout.close();
}
