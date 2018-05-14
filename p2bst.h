#include <cstddef>
#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;         // Data held at this node in tree
    Node<T>* left;  // Pointer to left child
    Node<T>* right; // Pointer to right child
};

template <typename T>
struct Tree {
    Node<T>* root; // Pointer to topmost (root) node
};

//provided functions **********************************
template <typename T>
void initialize(Tree<T> &t)
{
    t.root = NULL;
}

// This is the recursive destroy function, accepting a Node* argument.
template <typename T>
void destroy(Node<T>* n)
{
    if( n == NULL )
        return;
    
    destroy(n->left);  // Recursively destroy left subtree
    destroy(n->right); // Recursively destroy right subtree
    delete n;          // Delete this node
}

// This is the function called by the user, to destroy a Tree.
// It will call the recursive function, beginning with the root node.
template <typename T>
void destroy(Tree<T> &t)
{
    destroy(t.root);
    t.root = NULL;
}

template <typename T>
void insert(Tree<T> &t, T value)
{
    // Create new node to add to the tree
    Node<T>* newNode = new Node<T>;
    newNode->data  = value;
    newNode->left  = NULL;
    newNode->right = NULL;
    
    if( t.root == NULL ) { // empty tree
        t.root = newNode;
        return;
    }
        
    Node<T>* walker = t.root;
    while( true )
    {
        if( walker->data > value )
        {
            if( walker->left == NULL )
            {
                walker->left = newNode;
                return;
            }
            else
                walker = walker->left;
        }
        else // walker->data < value
        {
            if( walker->right == NULL )
            {
                walker->right = newNode;
                return;
            }
            else
                walker = walker->right;            
        }
    }
}

// Return depth (level) at which value appears
//    or 0 if value is not in tree
template <typename T>
int contains(Tree<T> &t, T value)
{
    Node<T>* walker = t.root;
    int depth = 1;
    
    while( walker != NULL )
    {
        if( walker->data == value )
            return depth;
        else if( walker->data > value )
            walker = walker->left;
        else // walker->data < value
            walker = walker->right;
        depth++;
    }
    return 0;
}

//implement these functions ***************************
//countNodes will return an integer indicating the number of (non-NULL) nodes currently in the tree
template <typename T>
int countNodes(Node<T>* n)
{	
	//when node is null returns 0
    if(n == NULL)
        return 0;
    
    //increases count for node and left and right subtree nodes
    return countNodes(n->left) + countNodes(n->right) + 1;
}

//this is the function called by the user
//sends in root node into the recursive counting function
template <typename T>
int countNodes(Tree<T> &t)
{
	//returns count of nodes from recursive call
    return countNodes(t.root);
}

//countLeaf will return the number of leaf nodes (no children) 
template <typename T>
int countLeaf(Node<T>* n)
{
	//when node is null returns 0
    if(n == NULL)
        return 0;
    
    //increases count for node if left and right subtree nodes are null
    if (n->left == NULL && n->right == NULL)
    	return 1;
    
    //make recursive call
    return countLeaf(n->left) + countLeaf(n->right);
}

//this is the function called by the user
//sends in root node into the recursive counting function
template <typename T>
int countLeaf(Tree<T> t)
{
	//returns count of nodes with no children from recursive call
    return countLeaf(t.root);
}

//countDouble will return the number of nodes with two children 
template <typename T>
int countDouble(Node<T>* n)
{
	//when node is null returns count
    if(n == NULL)
        return 0;
    
    //increases count for node if left and right subtree nodes are not null
    if (n->left != NULL && n->right != NULL)
    	return 1 + countDouble(n->left) + countDouble(n->right);
    	
    //make recursive call
    return countDouble(n->left) + countDouble(n->right);
}

//this is the function called by the user
//sends in root node into the recursive counting function
template <typename T>
int countDouble(Tree<T> t)
{	
	//returns count of nodes with two children from recursive call
    return countDouble(t.root);
}

//height will return the height of the tree (equal to the greatest node depth) or 0 if the tree is empty
template <typename T>
int height(Node<T>* n)
{
	//when node is null returns count
    if(n == NULL)
        return 0;
    
    //compares depths, keeps greatest depth
    int l = height(n->left);
    int r = height(n->right);
    
    if (l >= r)
    	return l+1;
    else //r >= l
    	return r+1;
}

//this is the function called by the user
//sends in root node into the recursive counting function
template <typename T>
int height(Tree<T> &t)
{
	if (t.root == NULL)
		return 0;
		
	return height(t.root);
}

//kthValue will accept an integer parameter k and return the kth smallest value in the tree
//for example, given some tree t, kthValue(t,1) will return the smallest value,
//kthValue(t,2) will return the 2nd smallest value, and kthValue(t,countNodes(t)) will return the largest value in the tree
//You may assume that there are at least k values (e.g., we will not look for the 5th value in a tree with 3 nodes).
template <typename T>
T kthValue(Node<T> *n, int k)
{
	int nodes = countNodes(n->left) + 1;
	
	//current position
	if (nodes == k)
		return n->data;
	
	//to the left
	if (k < nodes)
		return kthValue(n->left, k);
	
	//to the right
	else //k > nodes
		return kthValue(n->right, k - nodes);
}

//this is the function called by the user
template <typename T>
T kthValue(Tree<T> t, int k)
{
	return kthValue(t.root, k);
}
