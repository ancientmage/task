#pragma once
#include <string>
#include "Node.h"

class Node;
class Trie
{
	Node * head;
	int size;
public:
	Trie();
	~Trie();

	void add(const std::string & str, const std::string * str2 = 0);
	void remove(const std::string & str, const std::string * str2 = 0);
	void dicreaseSize();
	Trie * getValue(const std::string & str);
	std::vector<std::string> getAllKeys();
	void printAll();
	int getSize();
};

