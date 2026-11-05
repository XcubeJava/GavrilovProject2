#include "Autorization.hpp"
#include "ServiceFunctions.cpp"
void Start()
{

	while (true)
	{
		if (login())
		{

		}

		else
		{
			std::wcout << L"Всего доброго\n";
			Sleep(1500);
			break;
		}

	}
}


bool login()
{
	std::wstring login, pass;
	while (true)
	{
		system("cls");
		std::wcout << L"\n\n\n\t\t\tДобро\n\n\t\t\tOP\n\n\n";
		std::wcout << L"Введите логин или \"exit" "для выхода: ";
		Getline(login);
		if (login == L"exit" || login == L"Exit")
		{
			return false;
		}

		else

		{	
			std::wcout << L"Введите пароль: ";
			Getline(pass);


		}
	}

	return false;
}
