#include "ServiceFunctions.hpp"

#include <string>
#include <iostream>


void Getline(std::wstring& str)
{
	std::getline(std::wcin, str, L'\n');
}
