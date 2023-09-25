#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int Hash(char* word)
{
	int sum = 0;
	for (int i = 0; i < strlen(word); i++)
	{
		sum += word[i];
	}
	sum = sum % 10;
	return sum;
}

int Search(char* key, char** table)
{
	int index = Hash(key);
	if (strcmp(table[index], key) == 0)
	{
		return index;
	}
	else
	{
		return NULL;
	}
}

void main()
{
	setlocale(LC_ALL, "rus");
	char* k = (char*)malloc(256 * sizeof(char));
	const char* keys[10] = { "var", "Begin", "end", "if", "false", "true", "with", "until", "Char", "program" };
	char** table = (char**)malloc(10 * sizeof(char*));
	char* key = (char*)malloc(256 * sizeof(char));
	int index;
	for (int i = 0; i < 10; i++)
	{
		table[i] = nullptr;
	}
	int select = 0;
	while (1)
	{
		cout << "1 - Добавить 10 служебных слов\n2 - Добавить слово\n3 - Вывод\n4 - Поиск\n5 - Выход" << endl;
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			for (int i = 0; i < 10; i++)
			{
				cout << keys[i] << endl;
				key = (char*)malloc(256 * sizeof(char));
				strcpy(key, keys[i]);
				index = Hash(key);
				if (table[index] == NULL)
				{
					table[index] = (char*)malloc(sizeof(key));
					table[index] = key;
					cout << "Элемент успешно добавлен" << endl;
				}
			}
			cout << "Все слова добавлены добавлены" << endl;
			break;
		case 2:
			for (int i = 0; i < 10; i++)
			{
				cout << keys[i] << endl;
			}
			cout << "Введите одно из ключевых слов: ";
			key = (char*)malloc(256 * sizeof(char));
			scanf("%s", key);
			index = Hash(key);
			if (table[index] == NULL)
			{
				table[index] = (char*)malloc(sizeof(key));
				table[index] = key;
				cout << "Элемент успешно добавлен" << endl;
			}
			else
			{
				if (table[index] != NULL)
				{
					cout << "Элемент уже существует" << endl;
					break;
				}
				cout << "Таблица заполнена." << endl;
			}
			break;
		case 3:
			if (table != nullptr)
			{
				cout << "Хеш-таблица:" << endl;
				for (int i = 0; i < 10; i++)
				{
					if (table[i] != nullptr)
					{
						cout << "Индекс: " << i << " Ключ: " << table[i] << endl;
					}
				}
			}
			else
			{
				cout << "Таблица пуста" << endl;
			}
			break;
		case 4:
			if (table != NULL)
			{
				cout << "Введите ключ для поиска: ";
				scanf("%s", k);
				index = Hash(k);
				if (strcmp(table[index], k) == 0)
				{
					cout << "Индекс: " << index << endl;
				}
				else
				{
					cout << "Значение не найдено" << endl;
				}
			}
			else
			{
				cout << "Таблица пуста" << endl;
				system("pause");
			}
			break;
		case 5:
			return;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}
