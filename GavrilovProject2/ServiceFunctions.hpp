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

bool IsNumber(const std::wstring& str);
bool IsNotSave(std::wstring& chooseName, std::wstring* NameArr, size_t NameArrSize);

template <typename ArrType>
void ArrPushBack(ArrType*& arr,size_t size)
{
	size++;
	ArrType* temp = new ArrType[size];
	for (size_t i = 0; i < size - 1; i++)
	{
		temp[i] = arr[i];
	}
	std::swap(temp, arr)
	delete[]temp;/
}

#endif // !_ServiceFunctions_HPP