#pragma once
#include <iostream>
#include <string>
#include "TrieNode.h"
using namespace std;

class Trie {
private:
	TrieNode* root;
public:
	Trie() { this->setRoot(new TrieNode); };
	void setRoot(TrieNode* newRoot) {root = newRoot;}
	TrieNode* getRoot() { return this->root; }
	void printTrie();
	void insert(string newWord);
	bool searchWord(string s);
};

void Trie::insert(string newWord)
{
	TrieNode* rover = getRoot();

	if (newWord.length() == 0)
	{
		rover->setWordMarker();
		return;
	}

	for (size_t i = 0; i < newWord.length(); i++)
	{
		TrieNode* child = rover->findChild(newWord[i]);
		if (child != NULL)
		{
			rover = child;
		}
		else
		{
			TrieNode* temp = new TrieNode();
			temp->setChar(newWord[i]);
			rover->appendChild(temp);
			rover = temp;
		}
		if (i == newWord.length() - 1)
		{
			rover->incOccurrences();
			rover->setWordMarker();
		}
	}
}

bool Trie::searchWord(string deleteWord)
{
	TrieNode* rover = root;

	while (rover != NULL)
	{
		for (size_t i = 0; i < deleteWord.length(); i++)
		{
			TrieNode* temp = rover->findChild(deleteWord[i]);
			if (temp == NULL)
				return false;
			rover = temp;
		}

		if (rover->wordMarker())
		{
			std::cout << "\n~\tWord Found!" << std::endl;
			std::cout << "~\tOccurrences: " << rover->getOccurrences() << std::endl;
			return true;
		}
		else
			return false;
	}

	return false;
}