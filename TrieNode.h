#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#define ALPHABET_SIZE 26
#define WORD_SIZE_MAX 32

using namespace std;

class TrieNode {
private:
	char storedChar;
	bool isEndOfWord;
	bool definitionExists = false;
	std::vector<TrieNode*> wordChildren;
	int occurrences = 0;
	string definition;
	string wordType;
	bool typeExists;
public:
	TrieNode() { storedChar = ' '; isEndOfWord = false; }
	char getChar() { return storedChar; }
	void setChar(char c) { storedChar = c; }
	bool wordMarker() { return isEndOfWord; }
	void setDef(string def) { this->definition = def; this->definitionExists = true; }
	string getDef() { return definition; };
	bool defExists() { return this->definitionExists; }
	void setType(string type) { this->wordType = type; this->typeExists = true; }
	string getType() { return this->wordType; }
	bool getTypeExist() { return this->typeExists; }
	void incOccurrences() { this->occurrences++; }
	int getOccurrences() { return occurrences; }
	void setWordMarker() { isEndOfWord = true; }
	TrieNode* findChild(char c);
	void appendChild(TrieNode* child) { wordChildren.push_back(child); }
	std::vector<TrieNode*> children() { return wordChildren; }

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