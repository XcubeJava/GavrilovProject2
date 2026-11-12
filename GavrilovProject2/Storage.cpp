#include "Storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* pricrArr = nullptr;
bool IsStorageCreated = false;

void CreateStorage(int mode)
{
    if (mode == 0 && !IsStorageCreated)
    {
        const size_t staticSize = 6;
        size_t idArrStatic[staticSize]{ 1, 2, 3, 4, 5, 6 };
        std::wstring nameArrStatic[staticSize]
        {
            L"Промпт-инжиниринг: искусство управления ИИ",
            L"Нейросети для контент-мейкеров и SMM",
            L"ИИ для селлеров маркетплейсов (WB и Ozon)",
            L"Генерация видео для YouTube и TikTok",
            L"ИИ-автоматизация рутины в Make и n8n",
            L"ИИ для личной эффективности и работы с документами"
        };
        size_t countArrStatic[staticSize]{ 99, 99, 99, 99, 99, 99 };
        double priceArrStatic[staticSize]{ 3900, 4990, 6990, 5990, 8990, 2990 };

        sizeSt = staticSize;
        idArr = new size_t[sizeSt];
        nameArr = new std::wstring[sizeSt];
        countArr = new size_t[sizeSt];
        pricrArr = new double[sizeSt];

        FillArray(idArr, idArrStatic, sizeSt);
        FillArray(nameArr, nameArrStatic, sizeSt);
        FillArray(countArr, countArrStatic, sizeSt);
        FillArray(pricrArr, priceArrStatic, sizeSt);

        IsStorageCreated = true;
    }
    else if (mode == 1)
    {

    }
    else
    {
        std::wcout << L"Склад уже создан\n\n";
    }
}

void ShowStorage(int mode)
{
    if (mode == 0)
    {
        system("cls");
        std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t" <<
            L"Кол-во товара\t" << L"Цена\n\n";

        for (size_t i = 0; i < sizeSt; i++)
        {
            std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
                << L"\t\t" << countArr[i] << L"\t\t" << pricrArr[i] << L"\n";

        }
        std::wcout << L"\n";
        system("pause");
    }
}
