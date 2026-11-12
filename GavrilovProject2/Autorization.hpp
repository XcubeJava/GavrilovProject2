#ifndef _AUTORIZATION_HPP_
#define _AUTORIZATION_HPP_

#include <iostream>
#include <Windows.h>
#include <string>

#include "Accounts.hpp"
#include "storage.hpp"
#include "ServiceFunctions.hpp"

void Start();

bool login();

void SuperAdminMenu();

void AdminMenu();

void UserMenu();

#endif // !_AUTORIZATION_HPP