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
		node * search(void * value);
		void delete_tree();
		void preorderPrint();
		void postorderPrint();
		void inorderPrint();
		
        private:
		void inorderPrint(node *root );
  	        void preorderPrint(node *root); 
  	        void postorderPrint(node *root);
		void delete_tree(node *leaf);
		void insert(void * value, node *leaf);
		node * search(void * value, node *leaf);
	
		node *root;		
};



