/*
Artur Popov
V1.0
13th November

*/


#include "tree.h"
#include <iostream>
#include <typeinfo>

using namespace std;
//Constructor
//Sets deafault root to NULL
BinaryTree::BinaryTree()
{
	root = NULL;
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
	}
}

//Recursively finds spot to place value
//Uses static casting to compare the integers that the void pointer is pointing to
//Can be edited for any type by changing the comparisons plus casting to be appropriate for the type
void BinaryTree::insert(void * value, node * leaf)
{
	if(*static_cast<int*>(value) < *static_cast<int*>(leaf->m_value))
	{
		if(leaf->left != NULL)
			insert(value, leaf->left); //If node is taken, call itself while going left
		else
		{
			leaf->left=new node; //If node is NULL, create a node there 
			leaf->left->m_value = value; //Give new node the pointer to
			leaf->left->left = NULL; //NULL the left leaf
			leaf->left->right = NULL; //NULL THE RIGHT leaf
		}
	}
	else if(*static_cast<int*>(value) >= *static_cast<int*>(leaf->m_value))
	{
		if(leaf->right != NULL)
			insert(value, leaf->right);
		else
		{
			leaf->right=new node; //Ditto from above
			leaf->right->m_value = value;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}	
	}
}

node * BinaryTree::search(void * value)
{
	return search(value, root); //Return result of the recursive version
}

//Can be edited for any type by changing the comparisons plus casting to be appropriate for the type
node * BinaryTree::search(void * value, node * leaf)
{
	if(leaf != NULL) //If not found yet
	{
		if(*static_cast<int*>(value) == *static_cast<int*>(leaf->m_value)) //Dereferences void pointer
		{
			return leaf; //If FOUND return the correct leaf pointer
		}
		if(*static_cast<int*>(value) < *static_cast<int*>(leaf->m_value)) //if smaller than after dereferancing
		{
			return search(value, leaf->left); //Recursively call to go deeper into the left tree
		}
		else
		{
			return search(value, leaf->right); //Recursively call to go deeper into the right of the tree
		}
	}
	else return NULL;
}
//Calls the post order printing process
//Exists for the purpose that root is private and shouldn't be editable outside of tree functions
void BinaryTree::postorderPrint()
{
	postorderPrint(root); 
}
//Prints from left to right of tree
//Edit the cast for any type you like
void BinaryTree::postorderPrint( node *root ) 
{
	
        if ( root != NULL ) 
        { 
           postorderPrint( root->left );   
           postorderPrint( root->right );  
           cout << *static_cast<int*>(root->m_value) << " ";
        }
}

//Calls the pre order printing process
//Exists for the purpose that root is private and shouldn't be editable outside of tree functions
void BinaryTree::preorderPrint()
{
	preorderPrint(root);
}
//Prints from root to left to right of tree
//Edit the cast for any type you like
void BinaryTree::preorderPrint( node *root ) 
{
        if ( root != NULL ) 
        {
           cout << *static_cast<int*>(root->m_value) << " ";
           preorderPrint( root->left );
           preorderPrint( root->right );
        }
}
//Calls the post order printing process
//Exists for the purpose that root is private and shouldn't be editable outside of tree functions
void BinaryTree::inorderPrint() 
{
	inorderPrint(root);
}
//Prints inorder fashion
//Edit the cast for any type you like
void BinaryTree::inorderPrint(node *root ) 
{
        if ( root != NULL ) 
        { 
           inorderPrint( root->left );
           cout << *static_cast<int*>(root->m_value) << " ";
           inorderPrint( root->right );
        }
} 

