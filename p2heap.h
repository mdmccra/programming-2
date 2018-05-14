#include <cstddef>

const int HEAPSIZE = 128;

template <typename T>
struct Heap {
	T data[HEAPSIZE];
	int size;
};

template <typename T>
void initialize(Heap<T> &h)
{
	//set size to 0
	h.size = 0;
}

template <typename T>
void destroy(Heap<T> &h)
{
	//set size to 0
	h.size = 0;
}

template <typename T>
bool isEmpty(Heap<T> h)
{
	//check if size is 0
	return (h.size == 0);
}

template <typename T>
void put(Heap<T> &h, T value)
{
	//put in last slot
	h.size++;
	h.data[h.size] = value;
	
	//heapify
	int n = h.size;
	T copy;
	while(n > 0)
	{
		//if not in correct order, switch values
		if (h.data[n] < h.data[n/2] && n/2 > 0)
		{
			copy = h.data[n/2];
			h.data[n/2] = h.data[n];
			h.data[n] = copy;
		}		
		
		//half n so it moves to the parent
		n /= 2;
	}
}

template <typename T>
T get(Heap<T> &h)
{
	//get value to be returned
	T value = h.data[1];
	
	//move last value in heap to beginning
	h.data[1] = h.data[h.size];
	h.size--;
	
	//heapify
	int n = 1;
	T copy;
	bool b;
	while(n <= h.size)
	{
		//bool to tell whether anything happened 
		b = false;
		
		//if right subtree exists
		if ((n*2)+1 <= h.size)
		{
			//compare children
			if (h.data[(n*2)+1] < h.data[n*2])
			{
				//switch values if needed
				if (h.data[(n*2)+1] < h.data[n])
				{
					copy = h.data[(n*2)+1];
					h.data[(n*2)+1] = h.data[n];
					h.data[n] = copy;
					n*=2;
					n++;
					b = true;
				}
			}
			
			//other child is bigger
			else
			{
				//switch values if needed
				if (h.data[n*2] < h.data[n])
				{
					copy = h.data[n*2];
					h.data[n*2] = h.data[n];
					h.data[n] = copy;
					n*=2;
					b = true;
				}
			}	
		}
		
		//if right subtree does not exist, but left subtree does
		else if (n*2 <= h.size)
		{
			//switch if needed
			if (h.data[n*2] < h.data[n])
			{
				copy = h.data[n*2];
				h.data[n*2] = h.data[n];
				h.data[n] = copy;
				n*=2;
				b = true;
			}	
		}
		
		//if nothing changed, double n
		if (!b)
			n*=2;
	}
	
	//return the original value that was got
	return value;
}
