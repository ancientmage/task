#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include "Tester.h"
#include "MultiMap.h"

// You can enter one of the words {scan, find, delete, help}. Help for more info.
void Tester::test() 
{
	MultiMap multiMap;
	std::string str1, str2;
	while(true)
	{
		std::cin >> str1;
		if(str1 == "scan")
		{
			std::getline(std::cin, str1);
			if(str1[0] == ' ') str1 = str1.erase(0, 1);
			recursiveOpenAllFolders(str1, multiMap);
		}
		else if(str1 == "find")
		{
			std::cin >> str1;
			std::vector<std::string> ans = multiMap.get(str1);
			for(size_t i = 0; i < ans.size(); ++i, std::cout << "\n")
				std::cout << ans[i] << " ";
		}
		else if(str1 == "delete")
		{
			std::cin >> str1;
			std::getline(std::cin,str2);
			if(str2[0] == ' ') str2 = str2.erase(0, 1);
			multiMap.remove(str1, &str2);
		} 
		else if(str1 == "help")
		{
			std::cout << "Enter please scan, find, delete, size, print or exit\n";
		}
		else if(str1 == "print")
		{
			multiMap.print();
		}
		else if(str1 == "size")
		{
			std::cout << multiMap.getSize() << "\n";
		}
		else if(str1 == "exit")
		{
			break;
		}
		else std::cout << "there is no command \"" << str1 << "\"" << std::endl;
	}
}

void Tester::recursiveOpenAllFolders(const std::string & curFolder, MultiMap & multiMap)
{
	WIN32_FIND_DATA	dataCurFile; 
	std::string sDirectory = curFolder;
	std::string correctPath = curFolder;
	if(correctPath.back() == '*') correctPath.pop_back();
	if(correctPath.back() == '\\') correctPath.pop_back();
	if(sDirectory.back() != '\\') sDirectory.push_back('\\');
	HANDLE hCurDirectory = FindFirstFile((char*)((sDirectory + "*").c_str()), &dataCurFile);
	while(FindNextFile(hCurDirectory, &dataCurFile) != 0)
	{
		if(std::string(dataCurFile.cFileName) == "..")
			continue;
		if(dataCurFile.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			recursiveOpenAllFolders(sDirectory + dataCurFile.cFileName, multiMap);
		else
			multiMap.set(dataCurFile.cFileName, &correctPath);
	}
}
