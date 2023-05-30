//Программа №17 (РАЗДЕЛ 2, ТЕМА 4, ЗАДАНИЕ 2 ) - ВНУТРЕННЕЕ ХЕШИРОВАНИЕ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int hash(char *word, int m)
{
	int sum = 0;
	for (int i = 0; i < strlen(word); i++)
	{
		sum += (int)word[i];
	}
	return sum % m +1;
}

void main()
{
	setlocale(LC_ALL, "rus");
	int select = 0;
	int n, s;
	char *key = (char*)malloc(256 * sizeof(char));
	printf("Введите размер таблицы: ");
	scanf("%d", &n);
	char **table = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		table[i] = NULL;
	}
	while (select != 4)
	{
		printf("1)Добавить ключ\n2)Поиск\n3)Вывод таблицы\n4)Выход\n");
		scanf("%d", &select);
		if (select == 1)
		{
			char *key = (char*)malloc(256 * sizeof(char));
			printf("Введите значение ключа: ");
			scanf("%s", key);
			int index = hash(key, n);
			if (table[index] == NULL)
			{
				table[index] = (char*)malloc(sizeof(key));
				table[index] = key;
				printf("Элемент добавлен\n");
			}
			else
				if (!strcmp(table[index], key))
				{
					printf("Элемент уже существует\n");
					continue;
				}
				else
				{
					bool flag = false;
					for (int i = 0; i < n; i++)
					{
						int j = (hash(key, n) + i) % n;
						if (table[j] == NULL)
						{
							table[j] = (char*)malloc(sizeof(key));
							table[j] = key;
							printf("Элемент добавлен\n");
							flag = true;
							break;
						}
						else if (table[j] != NULL)
						{
							if (!strcmp(table[j], key))
							{
								printf("Элемент уже существует\n");
								flag = true;
								break;
							}
						}
					}
					if (!flag)
					{
						printf("Таблица заполнена, добавление невозможно.\n");
					}
				}
		}
		else if (select == 2)
		{
			int count = 0;
			char *key = (char*)malloc(256 * sizeof(char));
			printf("Введите значение ключа: ");
			scanf("%s", key);
			int index = hash(key, n);
			if (table[index] != NULL)
			{
				if (!strcmp(table[index], key))
				{
					printf("Элемент существует (индекс: %d)\n", index);
					printf("Кол-во сравнений: 1\n");
					continue;
				}
			}
			bool flag = false;
			for (int i = 0; i < n; i++)
			{
				int j = ((hash(key, n) + i) % n);
				if (table[j] == NULL)
				{
					continue;
				}
				count++;
				if (!strcmp(table[j], key))
				{
					printf("Элемент существует (индекс: %d)\n", j);
					printf("Кол-во сравнений: %d\n", count);
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				printf("Элемент не найден\n");
			}
		}
		else if (select == 3)
		{
			for (int i = 0; i < n; i++)
			{
				if (table[i] != NULL)
				{
					printf("Индекс: %d Ключ: %s.\n", i, table[i]);
				}
			}
		}
		else if (select == 4)
		{
			break;
		}
		system("pause");
	}
}