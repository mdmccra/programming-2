#include<cstddef> // includes NULL definition

template <typename T>
struct Node {
   T value;
   Node<T>* next;
};

template <typename T>
struct Stack {
   Node<T>* top;
};

template <class T>
void initialize(Stack<T> &s)
{
	//sets top of the stack to null
	s.top = NULL;
}

template <class T>
void destroy(Stack<T> &s)
{
	//create walker for node and point it at the top
	Node<T>* walker;
	walker = s.top;
	
	//until the top is outside of the linked list, point walker
	//at the next value, delete the top position, and set the top
	//equal to the position of the walker
	while(s.top != NULL)
	{
		walker = walker->next;
		delete s.top;
		s.top = walker;
	}
}

template <class T>
bool isEmpty(Stack<T> s)
{
	//if top is null, there is nothing in the list
	return (s.top == NULL);
}

template <class T>
void push(Stack<T> &s,T pushed)
{
	//create new node pointer
	Node<T>* n = new Node<T>;
	
	//set new node's value equal to the value being pushed in
	n->value = pushed;
	
	//make the next pointer of the new node point to the top
	n->next = s.top;
	
	//move the top to the new node
	s.top = n;
	
}

template <class T>
T pop(Stack<T> &s)
{
	//create a walker pointing at the top
	Node<T>* walker;
	walker = s.top;
	
	//make walker point at the next value
	walker = walker->next;
	
	//set value equal to what is being popped
	T value = s.top->value;
	
	//delete the top and move it to where the walker is
	delete s.top;
	s.top = walker;
	
	//return the popped value
	return value;
}
