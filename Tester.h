#pragma once
#include <string>
#include "MultiMap.h"

class Tester
{
public:
	void test();
	void recursiveOpenAllFolders(const std::string & curFolder, MultiMap & multiMap);
};

