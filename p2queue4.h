#include <cstddef>

template <class T>
struct Queue {
    T*  data;	// array of values
    int size;	// size of data array
    int head;	// index from which the next value will be read (on Pop)
    int tail;	// index at which the next value will be written (on Push)
};

template <class T>
void initialize(Queue<T> &q)
{
	//initialize each value of queue and create an array
	q.size = 2;
	q.head = 0;
	q.tail = 0;
	q.data = new T[q.size];
}

template <class T>
void destroy(Queue<T> &q)
{
	//set each value to 0 and destroy the array that has been created
	q.size = 0;
	q.head = 0;
	q.tail = 0;
	delete [] q.data;
	q.data = NULL;	
}

template <class T>
int getSize(Queue<T> q)
{
	//returns the absolute value of the space between the head and the tail
	if (q.tail >= q.head)
		return q.tail - q.head;
	return q.size - (q.head - q.tail);
}

template <class T>
bool isEmpty(Queue<T> q)
{
	//if head and tail are at the same spot, returns true because there is nothing in the queue
	return (q.head == q.tail);
}

template <class T>
T pop(Queue<T> &q)
{
	//sets the return value to the space where the head is at in the array
	T value = q.data[q.head];
	
	//increments the head's position
	q.head++;
	
	//wraps the head around if needed
	if (q.head == q.size)
		q.head = 0;
		
	//returns the popped value
	return value;
}

template <class T>
void push(Queue<T> &q, T value)
{
	if (getSize(q) == q.size - 1)
	{
		//allocate memory
		T* temp = new T[q.size*2];
		
		//copy everything over
		int i = 0;
		while (!isEmpty(q))
		{
			temp[i] = pop(q);
			i++;
		}	
			
		//double value of size
		q.size *= 2;
	
		//reset the value of head and tail
		q.head = 0;
		q.tail = i;
		
		//delete what q.data was pointing at and re assign where it is pointing at
		delete [] q.data;
		q.data = temp;
	}
	
	//input into the next available slot and increment the tail's position
	q.data[q.tail] = value;
	q.tail++;
	
	//wraps the tail around if needed
	if (q.tail == q.size)
		q.tail = 0;
}
