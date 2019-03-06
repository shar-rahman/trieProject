#pragma once
#include <vector>
#include <cstring>
#define ALPHABET_SIZE 26
#define WORD_SIZE_MAX 32

using namespace std;

class TrieNode {
public:
	TrieNode() { storedChar = ' '; isEndOfWord = false; }
	char getChar() { return storedChar; }
	void setChar(char c) { storedChar = c; }
	bool wordMarker() { return isEndOfWord; }
	void setWordMarker() { isEndOfWord = true; }
	TrieNode* findChild(char c);
	void appendChild(TrieNode* child) { wordChildren.push_back(child); }
	std::vector<TrieNode*> children() { return wordChildren; }

private:
	char storedChar;
	bool isEndOfWord;
	std::vector<TrieNode*> wordChildren;
	std::vector<int> occurences;
};
TrieNode* TrieNode::findChild(char key)
{
	for (size_t i = 0; i < this->children().size(); i++)
	{
		TrieNode* temp = this->children().at(i);
		if (temp->getChar() == key)
		{
			return temp;
		}
	}

	return NULL;
}