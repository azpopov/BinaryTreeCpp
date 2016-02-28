/*
Artur Popov
V1.0
13th November

*/


#include "tree.h"
#include <iostream>
#include <typeinfo>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <fstream>

using namespace std;
//Constructor
//Sets deafault root to NULL
//Sets default most_occuring to -1 after giving it a memory location
BinaryTree::BinaryTree()
{
	root = NULL;
	most_occuring = new node;
	most_occuring->occurance_counter = -1;
}
//destructor calls delete_tree
BinaryTree::~BinaryTree()
{
	delete_tree();
}
//Calls recursive function delete_tree(node *leaf) and sets Root to NULL which is essentially creating a brand new fresh tree
void BinaryTree::delete_tree()
{
	delete_tree(root);
	root= NULL;
}
//Recursively goes through the whole tree to delete everything that anything is pointed to
void BinaryTree::delete_tree(node *leaf)
{
  if(leaf!=NULL)
  {
    delete_tree(leaf->left);
    delete_tree(leaf->right);
    delete leaf;
  }
  return;
}
//Inserts to root if root is not set, else calls recursive version of itself while passing it root (which has a variable)
void BinaryTree::insert(void * value)
{
	
	if(root != NULL)
		insert(value, root);
	else
	{
		root = new node;
		root->m_value = value;
		root->left = NULL;
		root->right = NULL;
		root->occurance_counter = 1;
	}
}

//Recursively finds spot to place value
//Accepts void pointer but convers to char pointer in order to compare to other m_value
void BinaryTree::insert(void * value, node * leaf)
{
	//Using strcmp as alternative to string.compare(string string) in order to get result < 0 means it's smaller == 0 means it's the 		same string
	if(strcmp(static_cast<char*>(value), static_cast<char*>(leaf->m_value)) < 0)
	{
		if(leaf->left != NULL)
			insert(value, leaf->left); //If node is taken, call itself while going left
		else
		{
			leaf->left=new node; //If node is NULL, create a node there 
			leaf->left->m_value = value; //Give new node the pointer to
			leaf->left->left = NULL; //NULL the left leaf
			leaf->left->right = NULL; //NULL THE RIGHT leaf
			leaf->left->occurance_counter = 1;
		}
	}
	else if(strcmp(static_cast<char*>(value), static_cast<char*>(leaf->m_value)) > 0)
	{
		//cout << "in more than\n";
		if(leaf->right != NULL)
			insert(value, leaf->right);
		else
		{
			leaf->right=new node; //Ditto from above
			leaf->right->m_value = value;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
			leaf->right->occurance_counter = 1;
		}	
	}
	else //If strings are equal, add one to the occurance counter
		leaf->occurance_counter++;
}
//Prints the tree out alphabetically in accordance to the output.txt that we were given
//Into a file cleverly named output.txt
void BinaryTree::alphabetical_occurance_print()
{

		string filename = "output.txt";
		char * cstr = new char [filename.length()+1];
		std::strcpy (cstr, filename.c_str()); //Convert filename to appropriate format for fstreams
		try
		{
			ofstream filewriter(cstr, std::ofstream::out);
			
			alphabetical_occurance_print(root, &filewriter);
			find_most_occuring();
			filewriter << "(" << (char*)most_occuring->m_value << "," << most_occuring->occurance_counter << ") \n";
			filewriter.close();

		}

		catch(...)
		{

		}
			
		cout << "\noutput.txt created!\n\n";
	
}

//Goes through the tree inorder and posts in accordance to the output.txt
//converts the void pointer m_value to char pointer because we know that it is a 
//set of characters with a \0 terminating them.
void BinaryTree::alphabetical_occurance_print(node *root, ofstream * filewriter)
{
	if ( root != NULL ) 
        { 
           
           alphabetical_occurance_print( root->left , filewriter );
           *filewriter << "(" << (char*)root->m_value << "," << root->occurance_counter << ") \n";
           
		    
           
           
           alphabetical_occurance_print( root->right , filewriter );
        }
}
//goes through the ready tree comparing the occurance counters in order to print out the most occuring.
void BinaryTree::find_most_occuring()
{
	find_most_occuring(root);
}

void BinaryTree::find_most_occuring(node *root)
{
	if(root != NULL)
	{
           find_most_occuring( root->left );
           find_most_occuring( root->right );
           if(most_occuring->occurance_counter < root->occurance_counter)
			most_occuring = root;
         }  
}


