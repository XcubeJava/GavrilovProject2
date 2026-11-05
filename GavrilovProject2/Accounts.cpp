#include "Accounts.hpp"

size_t userSize = 3;
size_t currentId = 2;
std::wstring currentStatus;

std::wstring* LoginArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2"};
std::wstring* PassArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2" };
std::wstring* StatusArr = new std::wstring[userSize]{ L"superadmin", L"Admin", L"User" };

unsigned int* userId = new unsigned int[userSize] {0, 1, 2};