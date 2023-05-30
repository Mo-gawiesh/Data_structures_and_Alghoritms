//Программа №4 (Раздел 1, Тема 3, Номер 2) - МОДЕЛИРОВАНИЕ УПОРЯДОЧЕННОГО ЛИНЕЙНОГО СПИСКА НА БАЗЕ МАССИВА С УКАЗАТЕЛЯМИ.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>
const int N = 10;

struct List
{
	char mass[N];
	int count;
};

int search(List *list, int current)
{

	if (list->count == 0)
	{
		return -2;
	}
	for (int i = 0; i < list->count; i++)
	{
		if (list->mass[i] > current)
		{
			return i;
		}
	}
	return -1;
}

void Push(List *list)
{
	if (list->count == N)
	{
		printf("Список заполнен!\n");
		return;
	}
	int inf;
	printf("Введите величину:\n");
	scanf("%d", &inf);
	if (list->count != 0)
	{
		int _search = search(list, inf);
		if (_search == -1)
		{
			list->mass[list->count] = inf;
			list->count++;
			return;
		}
		for (int i = list->count; i > _search - 1; i--)
		{
			list->mass[i] = list->mass[i - 1];
		}
		list->mass[_search] = inf;
	}
	else if (list->count == 0)
	{
		list->mass[0] = inf;
	}
	list->count++;

}

int searchDeleted(List *list, int current)
{
	int k = -1;
	if (list->count == 0)
	{
		printf("Список пуст!");
		return -2;
	}
	for (int i = 0; i < list->count; i++)
	{
		if (list->mass[i] == current)
		{
			k = i;
			printf("Найден элемент под номером: %d\n", k + 1);
		}
	}
	return k;
}

void Delete(List *list, int current)
{
	if (list->count == 0)
	{
		printf("Список пуст!\n");
		return;
	}
	int _search = searchDeleted(list, current);
	if (_search == -1)
	{
		printf("Элемент не найден.\n");
		return;
	}
	for (int i = _search; i < list->count - 1; i++)
	{
		list->mass[i] = list->mass[i + 1];
	}
	list->count--;
}

void Show(List *list)
{
	if (list->count == 0)
	{
		printf("Список пуст.\n");
		return;
	}
	for (int i = 0; i < list->count; i++)
	{
		printf("%d\n", list->mass[i]);
	}
}

void main()
{
	setlocale(LC_ALL, "rus");
	List *list = (List*)malloc(sizeof(List));
	list->count = 0;
	int select = 0;
	while (select != 5)
	{
		printf("1)Добавить элемент.\n2)Удалить элемент.\n3)Вывод списка.\n4)Найти элемент.\n5)Выход.\n");
		scanf("%d", &select);
		if (select == 1)
		{
			Push(list);
			system("pause");
		}
		else if (select == 2)
		{
			int current;
			printf("Введите элемент, который хотите удалить.\n");
			scanf("%d", &current);
			Delete(list, current);
			system("pause");
		}
		else if (select == 3)
		{
			Show(list);
			system("pause");
		}
		else if (select == 4)
		{
			int current;
			printf("Введите элемент, который хотите найти.\n");
			scanf("%d", &current);
			int _search = searchDeleted(list, current);
			if (_search == -2)
			{
				printf("Список пуст.\n");
			}
			else if (_search == -1)
			{
				printf("Элемент не найден!");
			}
			system("pause");
		}
		else if (select == 5)
		{
			break;
		}
		system("cls");
	}
}