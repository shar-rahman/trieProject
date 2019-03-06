#include "Trie.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream inputFile;
	ofstream outputFile;
	string file;
	string toInsert;
	string search;
	int choice;
	int count = 0;
	Trie* dictionary = new Trie();
	cout << "Enter file to read: ";
	cin >> file;
	inputFile.open(file);
	outputFile.open(file, std::ios_base::app);
	cout << "Reading the English dictionary and storing in a trie." << endl;
	while (getline(inputFile, toInsert, ' '))
	{
		cout << "Entered: " << toInsert << endl;
		count++;
		dictionary->insert(toInsert);
	}
	cout << "Read in: " << count << " words." << endl;
	while (1)
	{
		cout << "\n\n\t  Trie Main Menu" << endl;
		cout << "\t==================" << endl;
		cout << "\t   1. Search" << endl;
		cout << "\t   2. Print Trie" << endl;
		cout << "\t   3. Insert" << endl;
		cout << "\t   4. Exit" << endl;
		cout << "\n\nEnter Choice: ";
		cin >> choice;
		if (choice == 1)
		{
			cout << "\tSearch method selected." << endl;
			cout << "Enter a word to search it.\nPress enter with a blank entry to exit." << endl;
			while (1)
			{
				cin.clear();
				cout << "Enter Word: ";
				cin >> search;
				if (search == "")
					break;
				else
				{
					cout << "Searching: " << search << endl;
					if (dictionary->searchWord(search))
						cout << "Word Found!" << endl << endl;
					else
						cout << "Word not found!" << endl << endl;
				}
			}
		}
		if (choice == 2)
		{
			cout << "This is a work in progress lol" << endl;
		}
		if (choice == 3)
		{
			cout << "\tInsert method selected." << endl;
			cout << "Enter a word to insert.\nPress enter with a blank entry to exit." << endl;
			while (1)
			{
				cin.clear();
				cout << "Enter word: ";
				cin >> search;
				if (toInsert == "")
					break;
				else
				{
					cout << "Inserting: " << toInsert << endl;
					dictionary->insert(toInsert);
					outputFile << endl << toInsert;
				}
			}
		}
		if (choice == 4)
			break;
	}
	cout << "Exiting...\n\n\n\n";
	system("pause");
	return 69;
}