#include <string>
#include <ctime>
#include <vector>
#include "MultiMap.h"

void MultiMap::set(const std::string & str, const std::string * str2)
{
	trie.add(str, str2);
}

void MultiMap::remove(const std::string & str, const std::string * str2)
{
	trie.remove(str, str2);
}

void MultiMap::print()
{
	trie.printAll();
}

std::vector<std::string> MultiMap::get(const std::string & str)
{
	Trie * findedTrie = trie.getValue(str);
	if(findedTrie == NULL)
		return std::vector<std::string>();
	return findedTrie->getAllKeys();
}

int MultiMap::getSize()
{
	return trie.getSize();
}
