/*
Artur Popov
V1.0
13th November
*/

#include <iostream>

using namespace std;
//Template for class taken from cprogramming.com - article by Alex Allain


//Stucture with pointers to the memory where data is stored, the left leaf and right leaf
struct node 
{
	void * m_value;  //Stores a void pointer
	long int occurance_counter;
	node * left; 
	node * right;
};

//BinaryTree
/*
Insert and Search functions take a void pointer that points to an integer. Editing details to work with specific type in tree.cpp
*/
class BinaryTree
{
	public:
		BinaryTree();
		~BinaryTree();
		
		void insert(void * value);
		void delete_tree();
		/*
		void preorderPrint();
		void postorderPrint();
		void inorderPrint();
		node * search(void * value);
		*/
		void alphabetical_occurance_print();
		void find_most_occuring();
		
        private:
        /*
		void inorderPrint(node *root );
  	        void preorderPrint(node *root); 
  	        void postorderPrint(node *root);
  	        node * search(void * value, node *leaf);
  	*/
		void delete_tree(node *leaf);
		void insert(void * value, node *leaf);
		void alphabetical_occurance_print(node *root, ofstream * filewriter);
		void find_most_occuring(node *root);
		
		node *root;	
		node *most_occuring;	
};



