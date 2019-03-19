#include "Trie.h"
#include "stdlib.h"
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

void mainMenuPrint();
void searchMethod(Trie* trie);
void insertMethod(Trie* trie);
void addDefinition(Trie* trie);
void printMethod(Trie* trie);
void print(TrieNode* root, char word[], int level);

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
	inputFile.open("bug_test.txt");
	outputFile.open("bug_test.txt", std::ios_base::app);
	cout << "Reading the English dictionary and storing in a trie." << endl;
	
	while (getline(inputFile, toInsert, '\n') && !inputFile.eof())
	{
		cout << "Entered: " << toInsert << endl;
		count++;
		dictionary->insert(toInsert);
	}
	cout << "Read in: " << count << " words." << endl;
	cout << "\n" << endl;
	system("pause");
	while (1)
	{
		mainMenuPrint();
		cin >> choice;
		cin.clear();
		if (choice == 1) 
			searchMethod(dictionary);
		if (choice == 2)
			printMethod(dictionary);
		if (choice == 3)
			insertMethod(dictionary);
		if (choice == 4)
			addDefinition(dictionary);
		if (choice == 5)
			break;
		else
		{
			cout << "Try again.\n";
		}
	}
	cout << "Exiting...\n\n\n\n";
	system("pause");
	return 0;
}

void addDefinition(Trie* trie)
{
	cout << flush;
	system("CLS");
	int choice;
	string definition, wordType, word;
	string listOfTypes[4] = { "verb", "noun", "adj", "adverb" };

	cout << "~\tBlank entry to exit." << endl;
	cin.ignore();
	while (1)
	{
		cout << "~\tEnter word to add definition & word type for > ";
		getline(cin, word, '\n');
		if (word == "")
			return;
		else if (trie->searchWord2(word))
		{
			cout << "~\tEnter definition > ";
			getline(cin, definition, '\n');
			cout << "\n\n~\t  Word Types" << endl;
			cout << "~\t==============" << endl;
			cout << "~\t1. Verb\n~\t2. Noun\n~\t3. Adjective\n~\t4. Adverb\n";
			cout << "\nEnter choice > ";
			cin >> choice;
			if (choice == 1)
				trie->setDef(word, definition, listOfTypes[0]);
			if (choice == 2)
				trie->setDef(word, definition, listOfTypes[1]);
			if (choice == 3)
				trie->setDef(word, definition, listOfTypes[2]);
			if (choice == 4)
				trie->setDef(word, definition, listOfTypes[3]);
			cin.ignore();
		}
		else
			cout << "~\tWord not found.\n\n";
	}
}
void searchMethod(Trie* trie)
{
	cout << flush;
	system("CLS");
	string search;
	cout << "~\tSearch method selected." << endl;

	cin.ignore();
	while (1)
	{
		cout << "~\tEnter Word > ";
		getline(cin, search, '\n');
		if (search == "\n" || search == " " || search == "")
		{
			cout << "asdf";
			break;
		}
		else
		{
			if (trie->searchWord(search))
			{
				cout << "\n\t~~~~~~~~~~~~~~~~~" << endl;
			}
			else
				cout << "~\tWord not found!" << endl << endl;
		}
	}
	return;
}

void insertMethod(Trie* trie) {
	cout << flush;
	system("CLS");

	string toInsert;
	cout << "*\tInsert Selected" << endl;
	cout << "*\t=================" << endl;
	cout << "*\tEnter a word to insert.\n*\tPress enter with a blank entry to exit.\n" << endl;
	cin.ignore();
	while (1)
	{
		cin.clear();
		cout << " Word Entry > ";
		getline(cin, toInsert, '\n');
		if (toInsert == "")
			break;
		else
		{
			cout << "*\t      ";
			for (size_t i = 0; i < toInsert.length(); i++, Sleep(25))
				cout << "^";
			trie->insert(toInsert);
			cout << "\n*\tWord inserted.\n" << endl;
		}
	}
	return;
}

void printMethod(Trie* trie) {
	cout << "\nHere is the tree printed by order of prefix: \n" << endl;
	char arr[1000];
	print(trie->getRoot(), arr ,0);
}

void print(TrieNode* root, char word[], int level) {
	
    if (root->wordMarker()) { 
        word[level] = '\0'; 
        cout << word << endl; 
    } 
  	
  	int x; 
    for (x = 0; x < root->children().size(); x++) {
        if (root->children()[x])  {  
           	word[level] = root->children()[x]->getChar(); 
            print(root->children()[x], word, level + 1); 
        } 
    } 

}

void mainMenuPrint()
{
	cout << flush;
	system("CLS");
	cout << "\n\n\t   Trie Main Menu" << endl;
	cout << "\t   =================" << endl;
	cout << "\t   1. Search" << endl;
	cout << "\t   2. Print Trie" << endl;
	cout << "\t   3. Insert" << endl;
	cout << "\t   4. Add Definition" << endl;
	cout << "\t   5. Open" << endl;
	cout << "\t   6. Save As" << endl;
	cout << "\t   7. Exit" << endl;
	cout << "\n\n Enter Choice > ";
}
