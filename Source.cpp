#include "Trie.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool searchMethod(Trie* trie);
bool insertMethod(Trie* trie);

ifstream inputFile;
ofstream outputFile;

int main()
{
	string file;
	string toInsert;
	string search;
	int choice;
	int count = 0;
	Trie* dictionary = new Trie();
	inputFile.open("english_dictionary2.txt");
	outputFile.open("english_dictionary2.txt", std::ios_base::app);
	cout << "Reading the English dictionary and storing in a trie." << endl;
	
	while (getline(inputFile, toInsert, '\n'))
	{
		cout << "Entered: " << toInsert << endl;
		count++;
		dictionary->insert(toInsert);
	}
	cout << "Read in: " << count << " words." << endl;
	while (1)
	{
		cout << "\n\n\t  Trie Main Menu" << endl;
		cout << "\t========================" << endl;
		cout << "\t   1. Search" << endl;
		cout << "\t   2. Print Trie" << endl;
		cout << "\t   3. Insert" << endl;
		cout << "\t   4. Add Definition" << endl;
		cout << "\t   5. Exit" << endl;
		cout << "\n\nEnter Choice: ";
		cin >> choice;
		if (choice == 1)
			while (searchMethod(dictionary))
				cout << "Search method exited" << endl;
		if (choice == 2)
		{
			cout << "This is a work in progress lol" << endl;
		}
		if (choice == 3)
			insertMethod(dictionary);
		if (choice == 5)
			break;
	}
	cout << "Exiting...\n\n\n\n";
	system("pause");
	return 69;
}

bool searchMethod(Trie* trie)
{
	string search;
	cout << "~\tSearch method selected." << endl;
	cout << "~\tEnter a word:" << endl;
	while (1)
	{
		cin.clear();
		cout << "~\tEnter Word > ";
		cin >> search;
		if (search == "")
			break;
		else
		{
			if (trie->searchWord(search))
			{
				cout << "~\t" << search << endl;
				cout << "~\t";
				for (int i = 0; i < search.length(); i++)
					cout << "^";
				cout << "\n";
			}
				
			else
				cout << "~\tWord not found!" << endl << endl;
		}
	}
	return false;
}

bool insertMethod(Trie* trie) {
	string toInsert;
	cout << "*\tInsert method selected." << endl;
	cout << "*\tEnter a word to insert.\nPress enter with a blank entry to exit." << endl;
	while (1)
	{
		cin.clear();
		cout << "*\tEnter word >";
		cin >> toInsert;
		if (toInsert == "\n")
			break;
		else
		{
			cout << "*\tInserting: " << toInsert << endl;
			trie->insert(toInsert);
			outputFile << endl << toInsert;
		}
	}
	return false;
}