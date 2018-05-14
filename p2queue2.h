const int SIZE = 5;
	
template <typename T>
struct Queue {
   T   data[SIZE];
   int head;
   int tail;
};

template <typename T>
void initialize(Queue<T> &q)
{
	//sets head and tail equal to zero to initialize the queue
	q.head = 0;
	q.tail = 0;
}

template <typename T>
void destroy(Queue<T> &q)
{
	//sets head and tail equal to zero to initialize the queue
	q.head = 0;
	q.tail = 0;
}

template <typename T>
bool isEmpty(Queue<T> q)
{
	//if head and tail are both at zero return true
	return (q.head == q.tail); 
}

template <typename T>
int getSize(Queue<T> q)
{
	//if tail is greater than head, subtract the head from the tail to calculate size
	//otherwise, subtract the head and tail from the variable SIZE
	if (q.tail >= q.head)
		return q.tail - q.head;
	return SIZE - (q.head - q.tail);		
}

template <typename T>
void push(Queue<T> &q, T in)
{
	//sets the current position of data[tail] equal to the number being pushed
	q.data[q.tail] = in;
	q.tail++;
	
	//wraps around when tail gets to end of the array data
	if (q.tail == SIZE)
		q.tail = 0;
}

template <typename T>
T pop(Queue<T> &q)
{
	//sets the value to be popped equal to the head and increments the head
	T value = q.data[q.head];
	q.head++;
	
	//wraps around when head gets to the end of the array
	if (q.head == SIZE)
		q.head = 0;
	
	//returns the value being popped
	return value;
}
