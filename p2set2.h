#include <cstddef>

template <typename T>
struct Set {
    T* data;
    int size;        
    int count;
};

template <typename T>
void initialize(Set<T> &s)
{
	//initialize each value of set and create an array
	s.size = 2;
	s.count = 0;
	s.data = new T[s.size];
}

template <typename T>
void destroy(Set<T> &s)
{
	//set each value to 0 and destroy the array that has been created
	s.size = 0;
	s.count = 0;
	delete [] s.data;
	s.data = NULL;
}

template <typename T>
bool isEmpty(Set<T> s)
{
	//if count is equal to 0, nothing is in the set
	return (s.count == 0);
}

template <typename T>
void insert(Set<T> &s, T value)
{
	//use a bool to see if value needs to be inserted into the array
	bool unique = true;
	
	//goes through array, if the value matches another value in the array nothing will happen
	for (int i = 0; i < s.count; i++)
		if (value == s.data[i])
		{
			unique = false;
			break;
		}
		
	//resizes array if needed	
	if (s.count == s.size && unique)
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
	
	//after array is possibly resized, if value is unique then inserts it into the array
	//and increments the count variable for the set
	if (unique)
	{
		s.data[s.count] = value;
		s.count++;
	}
}

template <typename T>
bool contains(Set<T> s, T value)
{
	//goes through array, if anything value matches something in the array returns true
	for (int i = 0; i < s.count; i++)
		if (value == s.data[i])
			return true;
	return false;
}

template <typename T>
void remove(Set<T> &s, T value)
{
	//goes through the array until it finds the needed value
	//replaces value with the last value in the array
	for (int i = 0; i < s.count; i++)
	{
		if (value == s.data[i])
		{
			s.count--;
			s.data[i] = s.data[s.count];
			break;
		}
	}
}

template <typename T>
int getSize(Set<T> s)
{
	//returns the count of the set which is also the size
	return s.count;
}

//intersection
template <typename T>
Set<T> operator&&(Set<T> a, Set<T> b)
{
	//declare result set to return
	Set<T> result;
	initialize(result);
	
	//go through each array comparing the contents
	//if a value in one set is equal to a value in another
	for (int i = 0; i < a.count; i++)
		for (int j = 0; j < b.count; j++)
			if (a.data[i] == b.data[j])
				insert(result, a.data[i]);
	
	return result;
}

//union
template <typename T>
Set<T> operator||(Set<T> a, Set<T> b)
{
	//declare result set to return
	Set<T> result;
	initialize(result);
	
	for (int i = 0; i < a.count; i++)
		insert(result, a.data[i]);
		
	for (int i = 0; i < b.count; i++)
		insert(result, b.data[i]);
		
	return result;
}

//difference
template <typename T>
Set<T> operator-(Set<T> a, Set<T> b)
{
	//declare result set to return and bool to track if a value is unique
	Set<T> result;
	initialize(result);
	bool unique = true;
	
	for (int i = 0; i < a.count; i++)
	{
		for (int j = 0; j < b.count; j++)
		{
			if (a.data[i] == b.data[j])
			{
				unique = false;
			}
		}
		
		if (unique)
			insert(result, a.data[i]);
			
		unique = true;
	}			
	
	return result;
}
