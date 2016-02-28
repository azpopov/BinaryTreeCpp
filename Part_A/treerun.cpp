/*
Artur Popov
V1.0
13th November

*/

//Program for Testing purposes
//Allows you to insert, delete tree, search for a specific integer in the tree
//Print in any orde you like


#include "tree.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdio.h>

using namespace std;

//
int main()
{
	BinaryTree tree;
	//choice variables
	char choice;
	int myint;
	void * void_value;
	string string_choice; //To measure length of input
	for(int i = 0; i > -1; i)
	{
		cout << "\npress i to insert an element into the hash table" << endl;
		cout << "press d to search for integer" << endl;
		cout << "press l to in order Print" << endl;
		cout << "press s to post order Print" << endl;
		cout << "press p to pre order print" << endl;
		cout << "press c to create a new tree and delete old one" << endl;
		cout << "press q to quit" << endl;
		cin >> string_choice;
		cout << "\n";
		if(string_choice.size() > 1)
			choice='w';
		else
			choice=string_choice.at(0);
		switch(choice)
		{
			case 'i':
				cout << "Please insert a value\nValue: ";
				cin >> myint;
				void_value = new int;
				*static_cast<int*>(void_value) = myint;
				tree.insert(void_value);
			break;
			case 'd':
				cout << "Please insert a value\nValue: ";
				cin >> myint;
				void_value = new int;
				*static_cast<int*>(void_value) = myint;
				if(tree.search(void_value) == NULL)
					cout << "\nIt's not in the tree\n";
				else
					cout << "\nIt's in the tree\n";
			break;
			case 'c':
				tree.delete_tree();
			break;
			case 'l':
				tree.inorderPrint();
			break;
			case 'p':
				tree.preorderPrint();
			break;
			case 'q' :
				cout << "\nExiting Progam Now\n\n";
				tree.delete_tree();
				exit(1);
			break;	
			case 's':
				tree.postorderPrint(); 
			break;
			default:
				cout <<"\nNot one of the OPTIONS\n\n";
			break;
		}
	}
	return 1;
}

