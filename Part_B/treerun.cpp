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
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;




//
int main()
{
	BinaryTree tree;
	//Used for reading with ss out of file
	string string_store;
	//Used for passing to the insert function
	char * void_value;
	//Used to read from the filereader
	stringstream ss;
	//Used to get the name of the txt file
	string book_name;
	//Used to  temporalily store the separated ready strings of the string_store
	vector<string>edited_string(5, "");
	try
	{
		ifstream filereader;
		cout << "Please give me name of the book file\nFilename: ";
		cin >> book_name;
		
		char * cstr = new char [book_name.length()+1]; //ifstream won't open properly unless I convert it a pointer to char array
		std::strcpy (cstr, book_name.c_str());
		filereader.open(cstr, ifstream::in);
		
		if(!filereader.is_open()) //If doesn't open
				cout <<"FAIL";
		while(filereader >> string_store) //Continue until reaching endoffile
		{
			transform(string_store.begin(), string_store.end(), string_store.begin(), ::tolower); //Transform current string to 																lowercase
			for(int i = 0; i < string_store.size(); i++) //Continue while not at the end of string_store
			{
				if(string_store.at(i) <= 'z' && string_store.at(i) >= 'a') // if at(i) is a letter of alphabet, begin 																storing new word
					ss << string_store.at(i);
				else 
					ss << " ";	//Separating the stored strings with spaces instead of special characters
			}
			
			for(int i = 0; ss >> edited_string[i]; i++) //As long as there are thigns to take out. 
			{
				void_value = new char [edited_string[i].size()+1]; //Allocate memory for the new string
				copy(edited_string[i].begin(), edited_string[i].end(), void_value); //Copy into the allocated memory
				void_value[edited_string[i].size()] = '\0'; //insert \0 at end of string
				tree.insert(void_value); //finally insert the pointer
			}
			ss.clear();	//Clear all flags of SS.
		}
		
	}
	catch(string e) //If error occurs, catch it. 
	{
		cout << e << "\nBoo\n";
	}
	tree.alphabetical_occurance_print(); //Prints out the correct output compared to output.txt
	tree.find_most_occuring(); //Prints out most occuring word
	tree.delete_tree(); //Deletes tree and frees memory to avoid leaks. 
	return 1; //Returns 1 as SUCCESS. 
}

