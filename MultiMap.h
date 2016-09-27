#pragma once
#include <vector>
#include <string>
#include "Trie.h"

class MultiMap
{
private:
	Trie trie; 
public:
	void set(const std::string & str, const std::string * str2 = 0);
	void remove(const std::string & str, const std::string * str2 = 0);
	void print();
	int getSize();
	std::vector<std::string> get(const std::string & str);
};
