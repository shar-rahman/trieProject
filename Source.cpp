#include "Trie.h"
#include "stdlib.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void mainMenuPrint();
void searchMethod(Trie* trie);
void insertMethod(Trie* trie);
void addDefinition(Trie* trie);
void printMethod(Trie* trie);
void printPrefix(TrieNode* trie, int n, char wordIndexes[]);

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

	std::cout << std::boolalpha;
	std::cout << "good: " << inputFile.good() << '\n'
		<< "bad:  " << inputFile.bad() << '\n'
		<< "fail: " << inputFile.fail() << '\n'
		<< "eof:  " << inputFile.eof() << '\n';
	
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
	}
	cout << "Exiting...\n\n\n\n";
	system("pause");
	return 69;
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
	cout << "*\tInsert method selected." << endl;
	cout << "*\tEnter a word to insert.\nPress enter with a blank entry to exit." << endl;
	while (1)
	{
		cout << "Word Entry > ";
		getline(cin, toInsert, '\n');
		if (toInsert == "")
			break;
		else
		{
			trie->insert(toInsert);
			cout << "\n*\tWord inserted." << endl;
		}
	}
	return;
}

void printMethod(Trie* trie) {
	int choice;
	cout << "\n\n\t  How would you like your Trie printed?" << endl;
	cout << "\t========================" << endl;
	cout << "\t   1. Print inorder" << endl;
	cout << "\t   2. Print preorder" << endl;
	cout << "\t   3. Print postorder" << endl;
	cout << "\t   4. Print by prefix" << endl;
	cout << "\n\nEnter Choice: ";
	cin >> choice;
	/*if (choice == 1)
		printInorder(trie);
	if (choice == 2)
		printPreorder(trie);
	if (choice == 3)
		printPostorder(trie);*/
	if (choice == 4) {
		cout << "\nHere is the tree printed by order of prefix: \n" << endl;
		char word[26];
		printPrefix(trie->getRoot(), 0, word);
	}
}

void printPrefix(TrieNode* root, int n, char wordIndexes[]) {
	if (root->wordMarker()) {
		wordIndexes[n] = '\0';
		cout << wordIndexes << endl;
	}
	vector<TrieNode*> kids = root->children();
	for (int x = 0; x < 26; x++) {
		if (kids[x]) {
			wordIndexes[n] = x + 'a';
			printPrefix(kids[x], n + 1, wordIndexes);
		}
	}
}

void mainMenuPrint()
{
	cout << flush;
	system("CLS");
	cout << "\n\n\t    Trie Main Menu" << endl;
	cout << "\t========================" << endl;
	cout << "\t   1. Search" << endl;
	cout << "\t   2. Print Trie" << endl;
	cout << "\t   3. Insert" << endl;
	cout << "\t   4. Add Definition" << endl;
	cout << "\t   5. Exit" << endl;
	cout << "\n\nEnter Choice: ";
}