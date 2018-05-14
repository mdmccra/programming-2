#include <cstddef> // includes NULL definition

template <typename V, typename R>
struct Node {
    V value;
    R priority;
    Node<V,R>* next;
    Node<V,R>* prev;    
};

template <typename V, typename R>
struct PriorityQueue {
    Node<V,R>* head;
};

template <typename V, typename R>
void initialize(PriorityQueue<V,R> &pq)
{
	//starts head pointing at null
	pq.head = NULL;
}

template <typename V, typename R>
void destroy(PriorityQueue<V,R> &pq)
{
	Node<V,R>* walker;
	walker = pq.head;
	while (pq.head != NULL)
	{
		walker = pq.head->next;
		delete pq.head;
		pq.head = walker;
	}
}

template <typename V, typename R>
bool isEmpty(PriorityQueue<V,R> pq)
{
	//head is null if empty
	return (pq.head == NULL);
}

template <typename V, typename R>
void push(PriorityQueue<V,R> &pq, V pushed, R rank)
{
	//create new node pointer
	Node<V,R>* n = new Node<V,R>;
	
	//set new node's value equal to the value being pushed in
	//and rank equal to the priority of the value being pushed in
	n->value = pushed;
	n->priority = rank;
	
	//special case if pq is empty
	if (isEmpty(pq))
	{
		pq.head = n;
		pq.head->next = pq.head;
		pq.head->prev = pq.head;
		return;
	}
	
	//find position to place new node in list
	Node<V,R>* walker;
	walker = pq.head;
		
	while (walker->priority >= n->priority)
	{
		walker = walker->next;
		if (walker == pq.head)
			break;
	}
	
	if (n->priority > pq.head->priority)
		pq.head = n;
		
	//assign placement if not a special case
	walker->prev->next = n;
	n->next = walker;
	n->prev = walker->prev;
	walker->prev = n;
}

template <typename V, typename R>
V pop(PriorityQueue<V,R> &pq)
{
	//create return value and node walker
	V popped;
	Node<V,R>* del;
	del = pq.head;
	
	//assign return value
	popped = pq.head->value;
	
	//delete the node being popped from and re assign pointers
	if (pq.head == pq.head->next)
		pq.head = NULL;
	else
	{
		pq.head = pq.head->next;
		pq.head->prev = del->prev;
		del->prev->next = pq.head;
	}
	delete del;	
	
	//return the value being popped
	return popped;
}
