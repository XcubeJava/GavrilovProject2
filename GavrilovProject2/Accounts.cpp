#include "Accounts.hpp"

size_t userSize = 3;
size_t currentId = 2;
std::wstring currentStatus;

std::wstring* loginArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2" };
std::wstring* passArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2" };
std::wstring* StatusArr = new std::wstring[userSize]{ L"SuperAdmin", L"Admin", L"User" };
size_t* userId = new size_t[userSize]{ 0, 1, 2 };
