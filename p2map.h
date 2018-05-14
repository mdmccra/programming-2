#include <cstddef>

template <typename K, typename V>
struct Node {
    K key;
    V value;
    Node<K,V>* next;
};

template <typename K, typename V>
struct Map {
    Node<K,V>** table;
    int size;
};

//overloaded hashing functions  
int hash(int key, int size) { 
    return key % size;
}

int hash(char key, int size) {
    return key % size;
}

template <typename K, typename V>
void initialize(Map<K,V> &m, int s)
{
	//set the size of the array
	m.size = s;
	
	//create a new array of node pointers with given size
	m.table = new Node<K,V>*[m.size];
	
	//set everything in the table equal to NULL
	for (int i = 0; i < m.size; i++)
		m.table[i] = NULL;
}

template <typename K, typename V>
void destroy(Map<K,V> &m)
{
	//declare node pointers
	Node<K,V>* walker;
	Node<K,V>* del;
	
	//go through each index of array
	for (int i = 0; i < m.size; i++)
	{
		del = m.table[i];
		
		//delete everything in the list
		while (m.table[i] != NULL)
		{
			walker = del->next;
			delete del;
			m.table[i] = walker;
			del = walker;
		}
	}
	
	//delete the array and reset size
	m.size = 0;
	delete [] m.table;
	m.table = NULL;
}

template <typename K, typename V>
void assign(Map<K,V> &m, K keyValue, V heldValue)
{
	//create new node
	Node<K,V>* n = new Node<K,V>;
	n->value = heldValue;
	n->key = keyValue;
	
	//get index
	int index = hash(keyValue, m.size);
	
	//special case for first element in list
	if (m.table[index] == NULL)
	{
		m.table[index] = n;
		n->next = NULL;
		return;
	}
	
	//create node walker
	Node<K,V>* walker = m.table[index];
	
	//go through linked list
	while (walker->next != NULL)
	{
		//replaces value if key already exists
		if (walker->key == n->key)
		{
			walker->value = n->value;
			delete n;
			return;
		}
		
		//moves walker
		walker = walker->next;
	}
	
	//special case for last item in list
	if (walker->key == n->key)
	{
		walker->value = n->value;
		delete n;
		return;
	}
	
	//put the new node in the list
	walker->next = n;
	n->next = NULL;
}

template <typename K, typename V>
void remove(Map<K,V> &m, K keyValue)
{
	//declare pointers and get index
	int index = hash(keyValue, m.size);
	Node<K,V>* walker = m.table[index];
	Node<K,V>* del;
	
	//special case for sirst item in list
	if (walker->key == keyValue)
	{
		del = walker;
		walker = walker->next;
		m.table[index] = walker;
		delete del;
		return;
	}
	
	//create prev node pointer which will always point to the
	//walker's previous node
	Node<K,V>* prev = m.table[index];
	
	//goes through linked list
	while (walker->next != NULL)
	{
		//removes key when found
		if (walker->next->key == keyValue)
		{
			del = walker->next;
			walker->next = del->next;
			delete del;
			return;
		}
		
		//moves walkers
		prev = walker;
		walker = walker->next;
	}
	
	//special case for last in list
	if (walker->key == keyValue)
	{
		prev->next = NULL;
		delete walker;
	}
}

template <typename K, typename V>
bool has_key(Map<K,V> m, K keyValue)
{
	//declare walker pointer and get index
	int index = hash(keyValue, m.size);
	Node<K,V>* walker = m.table[index];
	
	//special case for nothing in list
	if (m.table[index] == NULL)
		return false;
		
	//special case for only one element in list
	if (walker->key == keyValue)
		return true;
	
	//goes through linked list
	while (walker->next != NULL)
	{
		//returns true if key exists
		if (walker->key == keyValue)
			return true;
		
		//moves walker pointer
		walker = walker->next;
	}
	
	//special case for last in list
	if (walker->key == keyValue)
		return true;
	
	//returns false if never returning true prior
	return false;
}

template <typename K, typename V>
V lookup(Map<K,V> m, K keyValue)
{
	//declarewalker pointer and get index
	int index = hash(keyValue, m.size);
	Node<K,V>* walker = m.table[index];
	
	//go through linked list
	while (walker->next != NULL)
	{
		//return value for key
		if (walker->key == keyValue)
			return walker->value;
		
		//move walker
		walker = walker->next;
	}
	
	//special case for last value in list
	return walker->value;
}
