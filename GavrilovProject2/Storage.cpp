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

void AddProduct()
{
	std::wstring chooseId, chooseCount, choose;
	int id = 0;
	size_t count = 0;
	while (true)
	{
		ShowStorage(1);
		std::wcout << L"Введите id товара для пополнения или \"exit\" для выхода\n";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции пополнение товара";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id<0 || id>sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите количество товара для пополнения";
				Getline(chooseCount);

				if (IsNumber(chooseCount))
				{
					count = std::stoull(chooseCount);
					if (count <0 || count > maxStorageSize - currentStorageSize)
					{
						std::wcout << L"Некорректное количество! На складе осталось"
							<< maxStorageSize - currentStorageSize << L"Свободных мест\n\n";
						Sleep(2000);


					}
					else
					{
						while (true)
						{
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" ----> "
								<< countArr[id] + count << L"\n\n";
							std::wcout << L"Подтвердить?\n1-Да\n2-Нет\n\n Ввод:";
							Getline(choose);
							if (choose == L"1")
							{
								std::wcout << L"Товар успешно пополнен\n\n";
								countArr[id] += count;
								currentStorageSize += count;
								Sleep(1500);
								break;

							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена пополнения" << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}
}

void RemoveProduct()
{
	std::wstring chooseId, chooseCount, choose;
	int id = 0;
	size_t count = 0;
	while (true)
	{
		ShowStorage(2);
		std::wcout << L"Введите id товара для списания или \"exit\" для выхода\n";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции списание товара";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id<0 || id>sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите количество товара для списания";
				Getline(chooseCount);

				if (IsNumber(chooseCount))
				{
					count = std::stoull(chooseCount);
					if (count <0 || count > countArr[id])
					{
						std::wcout << L"Некорректное количество! На складе осталось"
							<< maxStorageSize - currentStorageSize << L"Выбраного товара\n\n";
						Sleep(2000);


					}
					else
					{
						while (true)
						{
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" ---->"
								<< countArr[id] - count << L"\n\n";
							std::wcout << L"Подтвердить?\n1-Да\n2-Нет\n\n Ввод:";
							Getline(choose);
							if (choose == L"1")
							{
								std::wcout << L"Товар успешно списан\n\n";
								countArr[id] -= count;
								currentStorageSize -= count;
								Sleep(1500);
								break;

							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена списания" << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}
}

void ChangePrice()
{
	std::wstring chooseId, choosePrice, choose;
	int id = 0;
	double price = 0;
	while (true)
	{
		ShowStorage(3);
		std::wcout << L"Введите id товара для списания или \"exit\" для выхода\n";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции изминение цены";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id<0 || id>sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите количество новую стоимость товара\n";
				Getline(choosePrice);

				if (IsNumber(choosePrice))
				{
					price = std::stoull(choosePrice);
					if (price <0 || price > maxPrice)
					{
						std::wcout << L"Некорректная цена! Макисмально возможная цена:"
							<< maxPrice << L" рублей\n\n";
						Sleep(2000);


					}
					else
					{
						while (true)
						{
							std::wcout << nameArr[id] << L"\t" << priceArr[id] << L" ---->"
								<< price << L"\n\n";
							std::wcout << L"Подтвердить?\n1-Да\n2-Нет\n\n Ввод:";
							Getline(choose);
							if (choose == L"1")
							{
								std::wcout << L"Цена успешно изменена\n\n";
								// :)
								priceArr[id] = price;
								Sleep(1500);
								break;

							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена изминения цены" << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}
}


void ChangeStorage()
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

void AddNewProduct()
{
	std::wstring chooseName, chooseCount, choosePrice, choose;
	size_t count = 0;
	double price = 0;
	while (true)
	{
		while (true)
		{
			system("cls");
			std::wcout << L"Введите название нового товара или \"exit\"для выхода";
			Getline(chooseName);
			if (chooseName == L"Exit" || chooseName == L"exit")
			{
				std::wcout << L"Отмена добавления нового товара\n\n";
				Sleep(1500);
				return;
			}

			if (chooseName.size() <3 || chooseName.size() > 40)
			{
				std::wcout << L"Ошибка отмены добавления нового товара";
				std::wcout << L"Допустимое значение 0 3 до 40 символов";
				std::wcout << L"Кол-во символов в названии вашего нового товара" << chooseName.size() << L"\n\n";
				Sleep(1500);
			}

			if (IsNotSave(chooseName, nameArr, sizeSt))
			{
				break;
			}
			else
			{
				std::wcout << L"Данный товар уже есть на складе";
			}
		}
		while (true)
		{
			system("cls");
			std::wcout << L"Введите название нового товара или \"exit\"для выхода";
			Getline(chooseName);
			if (chooseName == L"Exit" || chooseName == L"exit")
			{
				std::wcout << L"Отмена добавления нового товара\n\n";
				Sleep(1500);
				return;
			}
			if (IsNumber(chooseCount))
			{
				count = std::stoull(chooseCount);
				if (count <0 || count > maxStorageSize - currentStorageSize)
				{
					std::wcout << L"Некорректное количество! На складе осталось"
						<< maxStorageSize - currentStorageSize << L"Свободных мест\n\n";
					Sleep(2000);


				}
				else
				{
					break;
				}
			}
		}
		while (true)
		{
			system("cls");
			std::wcout << L"Введите цену нового товара или exit для выхода";
			Getline(chooseName);
			if (chooseName == L"Exit" || chooseName == L"exit")
			{
				std::wcout << L"Отмена добавления нового товара\n\n";
				Sleep(1500);
				return;
			}
			if (IsNumber(choosePrice))
			{
				price = std::stoull(choosePrice);
				if (price <0 || price > maxPrice)
				{
					std::wcout << L"Некорректная цена! Макисмально возможная цена:"
						<< maxPrice << L" рублей\n\n";
					Sleep(2000);


				}
			}
		}

		while (true)
		{
			system("cls");
			std::wcout << L"Новый товар " << chooseName << L"\n";
			std::wcout << L"Кол-во " << count << L"\n";
			std::wcout << L"Цена: " << price << L"\n";
			std::wcout << L"Подтвердить?\n1-Да\n2-Нет\n\n Ввод:";
			Getline(choose);
			if (choose == L"1")
			{
				std::wcout << L"Загрузка новых данных в базу";
				for (size_t i = 0; i < 3; i++)
				{
					Sleep(1600);
					std::wcout << L"";
				}
				ArrPushBack(idArr, sizeSt);
				ArrPushBack(nameArr, sizeSt);
				ArrPushBack(countArr, sizeSt);
				ArrPushBack(priceArr, sizeSt);
				sizeSt++;
			}
			else if (choose == L"2")
			{
				std::wcout << L"Отмена пополнения" << L"\n\n";
				Sleep(1500);
				break;
			}
			else
			{
				Err();
			}

		}
	}
}


