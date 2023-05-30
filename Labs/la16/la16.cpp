//Программа №16 (РАЗДЕЛ 2, ТЕМА 4, ЗАДАНИЕ 1 ) - БЕСКОНФЛИКТНАЯ ХЕШ-ТАБЛИЦА ДЛЯ ЗАДАННОГО НАБОРА ТЕКСТОВЫХ КЛЮЧЕЙ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int hash(char *word)
{
	int sum = 0;
	for (int i = 0; i < strlen(word); i++)
	{
		sum += word[i];
	}
	sum = sum % 10 +1;
	return sum;
}

int search(char *key, char **table)
{
	int index = hash(key);
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
	char *k = (char*)malloc(256 * sizeof(char));
	//char *keys[10] = { "var", "Begin", "end", "if", "false", "true", "with", "until", "Char", "program" };
	char **table = (char**)malloc(10 * sizeof(char*));
	for (int i = 0; i < 10; i++)
	{
		table[i] = NULL;
	}
	int select = 0;
	while (select != 4)
	{
		printf("1)Добавить\n2)Вывод\n3)Поиск\n4)Выход\n");
		scanf("%d", &select);
		if (select == 1)
		{
			char *key = (char*)malloc(256 * sizeof(char));
			printf("Введите одно из ключевых слов:\n");
			/*for (int i = 0; i < 10; i++)
			{
				puts(keys[i]);
			}*/
			scanf("%s", key);
			int index = hash(key);
			if (table[index] == NULL)
			{
				table[index] = (char*)malloc(sizeof(key));
				table[index] = key;
				printf("Элемент успешно добавлен\n");
			}
			else
			{
				if (table[index] != NULL)
				{
					printf("Элемент уже существует\n");
				}
			}
		}
		else if (select == 2)
		{
			if (table != NULL)
			{
				printf("Хеш-таблица:\n");
				for (int i = 0; i < 10; i++)
				{
					if (table[i] != NULL)
					{
						printf("Индекс: %d Ключ: %s\n", i, table[i]);
					}
				}
			}
			else
			{
				printf("Таблица пуста\n");
			}
		}
		else if (select == 3)
		{
			if (table != NULL)
			{
				printf("Введите ключ для поиска:\n");
				scanf("%s", k);
				int index = hash(k);
				if (strcmp(table[index], k) == 0)
				{
					printf("Индекс: %d\n", index);
				}
				else
				{
					printf("Значение не найдено\n");;
				}
			}
			else
			{
				printf("Таблица пуста\n");
				system("pause");
			}
		}
		else if (select == 4)
		{
			break;
		}
		system("pause");
		system("cls");
	}
}
