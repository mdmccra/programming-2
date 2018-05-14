#include<cstddef> // includes NULL definition

template <class T>
struct Stack {
   T*  data;	// array of values
   int size;	// size of array
   int top;	// index of value currently at top of Stack
};

template <class T>
void initialize(Stack<T> &s)
{
	//start size of array at 2
	//top of stack is at the first slot
	//create a new array of size 2
	s.size = 2;
	s.top = 0;
	s.data = new T[s.size];
}

template <class T>
void destroy(Stack<T> &s)
{
	//set size and top equal to 0
	//delete the block of memory
	//set the pointer to NULL
	s.size = 0;
	s.top = 0;
	delete [] s.data;
	s.data = NULL;
}

template <class T>
bool isEmpty(Stack<T> s)
{
	//if the top is at 0, then nothing is in the stack
	if (s.top == 0)
		return true;
	return false;
}

template <class T>
void push(Stack<T> &s,T value)
{
	if (s.top == s.size)
	{
		//allocate memory
		T* temp = new T[s.size*2];
		
		//copy everything over
		for (int i = 0; i < s.size; i++)
			temp[i] = s.data[i];
		
		//double value of size
		s.size *= 2;
		
		//delete what s.data was pointing at and re assign where it is pointing at
		delete [] s.data;
		s.data = temp;
	}
	
	//input into the next available slot and increment the top position
	s.data[s.top] = value;
	s.top++;
}

template <class T>
T pop(Stack<T> &s)
{
	//move the top down an index and return the value that is there
	s.top--;
	return s.data[s.top];
}
