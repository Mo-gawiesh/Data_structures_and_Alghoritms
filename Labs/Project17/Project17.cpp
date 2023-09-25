#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int Hash(char* word, int m)
{
	int sum = 0;
	for (int i = 0; i < strlen(word); i++)
	{
		sum += (int)word[i];
	}
	return sum % m;
}

void main()
{
	setlocale(LC_ALL, "rus");
	int select = 0;
	int n, s;
	char* key = (char*)malloc(256 * sizeof(char));
	printf("Введите размер таблицы: ");
	scanf("%d", &n);
	char** table = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		table[i] = NULL;
	}
	int index, j, count = 0;
	bool flag;
	while (1) {
		printf("1 - Добавить ключ\n2 - Поиск\n3 - Вывод таблицы\n4 - Выход\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			key = (char*)malloc(256 * sizeof(char));
			printf("Введите значение ключа: ");
			scanf("%s", key);
			index = Hash(key, n);
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
						int j = (Hash(key, n) + i) % n;


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
			break;
		case 2:
			key = (char*)malloc(256 * sizeof(char));
			printf("Введите значение ключа: ");
			scanf("%s", key);
			index = Hash(key, n);
			if (table[index] != NULL)
			{
				if (!strcmp(table[index], key))
				{
					printf("Элемент существует (индекс: %d)\n", index);
					printf("Кол-во сравнений: 1\n");
					break;
				}
			}
			for (int i = 0; i < n; i++)
			{
				j = ((Hash(key, n) + i) % n);
				if (table[j] == NULL)
				{
					continue;
				}
				count++;
				if (!strcmp(table[j], key))
				{
					printf("Элемент существует (индекс: %d)\n", j);
					printf("Кол-во сравнений: %d\n", count);
					break;
				}
			}

			printf("Элемент не найден\n");

			break;
		case 3:
			for (int i = 0; i < n; i++)
			{
				if (table[i] != NULL)
				{
					printf("Индекс: %d Ключ: %s.\n", i, table[i]);
				}
			}
			break;
		case 4:
			return;
			system("pause");
		}
	}
}