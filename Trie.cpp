#include <string>
#include <vector>
#include "Trie.h"

Trie::Trie(void)
{
	size = 0;
	head = new Node();
}


Trie::~Trie(void)
{
	delete head;
}

void Trie::add(const std::string & str, const std::string * str2)
{
	Node * node = head;
	if(node == NULL)
		node = new Node();
	if(head->add(str, 0, str2)) ++size;
}

void Trie::printAll()
{
	if(head == NULL) return;
	std::string s = "";
	head->printAll(s);
}

void Trie::remove(const std::string & str, const std::string * str2)
{
	if(head->remove(str, 0, str2))
		dicreaseSize();
}

int Trie::getSize()
{
	return size;
}

Trie * Trie::getValue(const std::string & str)
{
	Node * node = head;
	for(size_t i = 0; i < str.size(); ++i)
	{
		node = node->getEdge(str[i]);
		if(node == NULL) return NULL;
	}
	return node->getTrie();
}

std::vector<std::string> Trie::getAllKeys()
{
	std::vector<std::string> ans;
	std::string tmp = "";
	head->findAll(tmp, ans);
	return ans;
}

void Trie::dicreaseSize()
{
	--size;
}