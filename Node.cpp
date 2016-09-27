#include <map>
#include <vector>
#include <iostream>
#include "Node.h"

Node::Node(void)
{
	isLeaf = false;
	trie = NULL;
}

Node::~Node(void)
{
	if(trie) delete trie;
}

bool Node::add(const std::string & str, int ind, const std::string * str2 )
{
	if(ind == str.size())
	{
		bool res = !isLeaf;
		isLeaf = true;
		if(trie == NULL && str2 != NULL) trie = new Trie();
		if(str2) trie->add(*str2);
		return res;
	}
	if(edges.find(str[ind]) == edges.end())
		edges[str[ind]] = new Node();
	return edges[str[ind]]->add(str, ind+1, str2);
}

void Node::printAll(std::string & str)
{
	if(isLeaf) std::cout << str << "\n";
	for(std::map<char, Node *>::iterator i = edges.begin(); i != edges.end(); ++i)
	{
		str.push_back(i->first);
		i->second->printAll(str);
		str.pop_back();
	}
}

int Node::remove(const std::string & str, int ind, const std::string * str2)
{
	if(ind == str.size())
	{
		if(str2 == NULL)
		{
			isLeaf = false;
			return 2 - (edges.size() == 0);
		}
		else
		{
			trie->remove(*str2);
			return trie->getSize() == 0;
		}
	}
	char nextChar = str[ind];
	if(edges.find(nextChar) == edges.end())
		return 0;
	int res = edges[nextChar]->remove(str, ind + 1, str2);
	if(res == 1)
	{
		delete edges[nextChar];
		edges.erase(nextChar);
		if(edges.size() == 0 && !isLeaf)
			return 1;
		return 2;
	}
	return res;
}

Node * Node::getEdge(char c)
{
	if(edges.find(c) == edges.end())
		return NULL;
	return edges[c];
}

Trie * Node::getTrie()
{
	return trie;
}

void Node::findAll(std::string & str, std::vector<std::string> & ans)
{
	if(isLeaf) ans.push_back(str);
	for(std::map<char, Node *>::iterator i = edges.begin(); i != edges.end(); ++i)
	{
		str.push_back(i->first);
		i->second->findAll(str, ans);
		str.pop_back();
	}
}