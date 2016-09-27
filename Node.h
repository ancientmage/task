#pragma once
#include "Trie.h"
#include <map>

class Trie;

class Node
{
private:
	bool isLeaf;
	std::map<char, Node*> edges;
	Trie * trie;
public:
	Node();
	~Node();
	Node * getEdge(char c);
	Trie * getTrie();
	bool add(const std::string & str, int ind, const std::string * str2 = 0);
	Trie * find(const std::string & str, int ind);
	void printAll(std::string & str);
	void findAll(std::string & str, std::vector<std::string> & ans);
	int remove(const std::string & str, int ind, const std::string * str2 = 0);
};
