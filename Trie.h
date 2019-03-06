#pragma once
#include "TrieNode.h"


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
			rover->setWordMarker();
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
			return true;
		else
			return false;
	}

	return false;
}