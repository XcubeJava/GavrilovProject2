#include "Autorization.hpp"
#include "ServiceFunctions.hpp"
void Start()
{

	while (true)
	{
		if (login())
		{
			if (currentStatus == L"SuperAdmin")
			{
                CreateStorage();
                SuperAdminMenu();
			}
            if (currentStatus == L"User")
            {
                CreateStorage();
            }
            if (currentStatus == L"Admin")
            {
                CreateStorage();
            }
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
        std::wcout << L"Введите логин или \"exit\" для выхода: ";
        Getline(login);
        if (login == L"exit" || login == L"Exit")
            return false;

        std::wcout << L"Введите пароль: ";
        Getline(pass);

        bool found = false;
        for (size_t i = 0; i < userSize; i++)
        {
            if (login == loginArr[i] && pass == passArr[i])
            {
                currentId = userId[i];
                currentStatus = StatusArr[i];
                std::wcout << L"Добро пожаловать, " << loginArr[i]
                    << L". Ваш уровень доступа: " << StatusArr[i] << L'\n';
                Sleep(1500);
                found = true;
                break;
            }
        }

        if (!found)
        {
            std::wcout << L"Неверный логин или пароль, повторите попытку\n";
            Sleep(1500);
        }
        else
            return true;
    }
}

void SuperAdminMenu()
{
    std::wstring choose;
    while (true) 
    {
        system("cls");
        std::wcout << L"1 - начать продажу\n";
        std::wcout << L"2 - показать товары\n";
        std::wcout << L"3 - пополнить товары\n";
        std::wcout << L"4 - сменить товары\n";
        std::wcout << L"5 - изменить цену\n";
        std::wcout << L"6 - Редактировать склад\n";
        std::wcout << L"7 - Редактировать сотрудников\n";
        std::wcout << L"8 - Отчёт о прибыли\n";
        std::wcout << L"0 - Выход\n\n";        
        std::wcout << L"0 - Ввод ";
        Getline(choose);

        if (choose == L"1")
        {

        }

        else if (choose == L"2")
        {
            ShowStorage();
        }
        else if (choose == L"3")
        {
            AddProduct();
        }
        else if (choose == L"4")
        {

        }
        else if (choose == L"5")
        {

        }
        else if (choose == L"6")
        {

        }
        else if (choose == L"7")
        {

        }
        else if (choose == L"8")
        {

        }
        else if (choose == L"0")
        {

        }



    }

}
