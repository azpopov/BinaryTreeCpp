#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <cstdlib>


using namespace std;
int main()
{
	string temp = "you--jem's";
	stringstream ss;
	string string_store = "you--jem's";
	for(int i = 0; i < string_store.size(); i++)
			{
				if(string_store.at(i) <= 'z' && string_store.at(i) >= 'a')
				{
					ss << string_store.at(i);
				}
				else 
				{
					ss << " ";
					string_store.erase(i, 1);
					i--;
				}	
			}
	while(ss >> string_store)
	{
		cout << string_store;
	}
	return 1;
}

