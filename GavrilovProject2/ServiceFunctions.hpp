#ifndef _ServiceFunctions_HPP_
#define _ServiceFunctions_HPP_
#include <string>
#include <iostream>
#include <iomanip>
#include <Windows.h>

void Getline(std::wstring& str);

template<typename Arrtype>
void FillArray(Arrtype* dynamiArr, Arrtype* staticArr, size_t commonSize)
{
	for (size_t i = 0; i < commonSize; i++)
	{
		dynamiArr[i] = staticArr[i];
	}
}

inline void Err()
{
	std::wcout << L"Некоректный ввод";
	Sleep(1500);
}

#endif // !_ServiceFunctions_HPP