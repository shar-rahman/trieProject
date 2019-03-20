#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TrieNode {
private:
	//Essential
	char storedChar;
	bool isEndOfWord;
	std::vector<TrieNode*> wordChildren;
	//For program functions
	bool definitionExists;
	int occurrences;
	string definition;
	string wordType;
	bool typeExists;
public:
	//Constructor & Setters
	TrieNode() { storedChar = ' '; isEndOfWord = false; definitionExists = false; occurrences = 0; }
	void setChar(char c) { this->storedChar = c; }
	void setDef(string def) { this->definition = def; this->definitionExists = true; }
	void setType(string type) { this->wordType = type; this->typeExists = true; }
	void setWordMarker() { this->isEndOfWord = true; }
	void incOccurrences() { this->occurrences++; }
	//Getters
	char getChar() { return this->storedChar; }
	bool wordMarker() { return this->isEndOfWord; }
	string getDef() { return this->definition; };
	bool defExists() { return this->definitionExists; }
	string getType() { return this->wordType; }
	bool getTypeExist() { return this->typeExists; }
	int getOccurrences() { return this->occurrences; }
	//Trie Functions
	TrieNode* findChild(char c);
	void appendChild(TrieNode* child) { this->wordChildren.push_back(child); }
	std::vector<TrieNode*> children() { return this->wordChildren; }
	~TrieNode() { delete this; }

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