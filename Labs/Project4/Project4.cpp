#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>

const int N = 5; 

struct SList
{
	char Mass[N];
	int Counter;
};

void Search(SList* List, int Number) {
	if (List->Counter == 0)
	{
		printf("Список пуст.\n");
		return;
	}
	for (int i = 0; i < List->Counter; i++)
	{
		if (List->Mass[i] == Number)
		{
			printf("Элемент найден под индексом %d\n", i);
			return;
		}
	}
	printf("Элемент не найден.\n");
	return;
}

void Add(SList* List)
{
	if (List->Counter == N)
	{
		printf("Список полон.\n");
		return;
	}
	int Number;
	printf("Введите информационную часть:\n");
	scanf("%d", &Number);
	if (List->Counter != 0)
	{
		int i;
		for (i = 0; i != List->Counter; i++) {
			if (List->Mass[i] > Number) {
				for (int k = List->Counter + 1; k != i; k--) {
					List->Mass[k] = List->Mass[k - 1];
				}
				break;
			}
		}
		List->Mass[i] = Number;
	}
	else if (List->Counter == 0)
	{
		List->Mass[0] = Number;
	}
	List->Counter++;
}
void Delete(SList* List, int Number)
{
	if (List->Counter == 0)
	{
		printf("Список пуст!\n");
		return;
	}
	for (int i = 0; i < List->Counter; i++) {
		if (List->Mass[i] == Number) {
			for (int k = i; k < List->Counter; k++) {
				List->Mass[k] = List->Mass[k + 1];
			}
			printf("Элемент удален.\n");
			List->Counter--;
			return;
		}
	}
	printf("Элемент не найден.\n");
}
void Show(SList* List)
{
	if (List->Counter == 0)
	{
		printf("Список пуст.\n");
		return;
	}
	for (int i = 0; i < List->Counter; i++)
	{
		printf("%d\n", List->Mass[i]);
	}
}

void main()
{
	setlocale(LC_ALL, "rus");
	SList* List = (SList*)malloc(sizeof(SList));
	List->Counter = 0;
	int select = 0;
	while (select != 5)
	{
		printf("1)Добавить элемент.\n2)Удалить элемент.\n3)Вывод списка.\n4)Найти элемент.\n5)Выход.\n");
		scanf("%d", &select);
		if (select == 1)
		{
			Add(List);
			system("pause");
		}
		else if (select == 2)
		{
			int current;
			printf("Введите элемент, который хотите удалить.\n");
			scanf("%d", &current);
			Delete(List, current);
			system("pause");
		}
		else if (select == 3)
		{
			Show(List);
			system("pause");
		}
		else if (select == 4)
		{
			if (List != nullptr && List->Counter == 0) {
				printf("Список пуст.\n");
				continue;
			}
			int Number;
			printf("Введите элемент, который хотите найти.\n");
			scanf("%d", &Number);
			Search(List, Number);
			system("pause");
		}
		else if (select == 5)
		{
			return;
		}
		system("cls");
	}
}