//Программа №5 (Раздел 1, Тема 3, Номер 3) - ЛИНЕЙНЫЙ СПИСОК НА БАЗЕ МАССИВА С УКАЗАТЕЛЯМИ - ИНДЕКСАМИ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

const int N = 10;
int number = 0;

struct List
{
	int x;
	int Next;
};
void Show(List *list)
{
	int current = list[0].Next;
	for (int i = 0; i < number; i++)
	{
		printf("%d\n", list[current].x);
		current = list[current].Next;
	}
	if (number == 0)
	{
		printf("Список пуст\n");
	}
}
int Poisk(List *list)
{
	int k = 0;
	for (int i = 1; i < N; i++)
	{
		if (list[i].Next == -1)
		{
			k = i;
			break;
		}
	}
	return k;
}
void Start(List *list, int k)
{
	system("cls");
	printf("Введите новый элемент:\n");
	int value;
	scanf("%d", &value);
	list[k].Next = list[number].Next;
	list[number].Next = k;
	number++;
	list[k].x = value;
	printf("Элемент добавлен\n");
}
void After(List *list)
{
	int k = Poisk(list);
	if (k != 0)
	{
		if (number == 0)
		{
			Start(list, k);
		}
		else {
			int kod;
			int kolvo = 0;
			printf("Введите значение элемента, после которого вы хотите добавить\n");
			scanf("%d", &kod);
			int current = list[0].Next;
			for (int i = 0; i < number; i++)
			{
				if (list[current].x == kod)
				{
					if (number < N)
					{
						int a;
						printf("Значение нового элемента - ");
						scanf("%d", &a);
						list[k].Next = list[current].Next;
						list[current].Next = k;
						list[k].x = a;
						number++;
						printf("Элемент добавлен\n");
					}
					else { printf("Список заполнен!\n"); }
					break;
				}
				current = list[current].Next;
			}
		}
	}
	else {
		printf("Список заполнен!\n");
	}
}
void Before(List *list)
{
	int k = Poisk(list);
	if (k != 0)
	{
		if (number == 0)
		{
			Start(list, k);
		}
		else {
			int kod;
			int kolvo = 0;
			printf("Введите значение элемента, до которого вы хотите добавить элемент\n");
			scanf("%d", &kod);
			int current = list[0].Next;
			int last = 0;
			for (int i = 0; i < number; i++)
			{
				if (list[current].x == kod)
				{
					int a;
					printf("Введите значение нового элемента- ");
					scanf("%d", &a);
					if (number < N)
					{
						list[k].Next = current;
						list[last].Next = k;
						list[k].x = a;
						number++;
					}
					break;
				}
				current = list[current].Next;
				last = list[last].Next;
			}
		}
	}
	else {
		printf("Список заполнен!\n");
	}
}
void Delete(List *list)
{
	if (number == 0)
	{
		printf("Список пуст.\n");
	}
	else {
		int a;
		printf("Введите значение элемента, которое вы хотите удалить:\n");
		scanf("%d", &a);
		int current = list[0].Next;
		int last = 0;
		for (int i = 0; i < number; i++)
		{
			if (list[current].x == a)
			{
				list[last].Next = list[current].Next;
				list[current].Next = -1;
				number--;
				printf("Элемент удалён!\n");
				break;
			}
			current = list[current].Next;
			last = list[last].Next;
		}
	}
}
void Search(List *list)
{
	if (number != 0)
	{
		int a;
		int k = 0;
		printf("Введите значение для поиска:\n");
		scanf("%d", &a);
		int current = list[0].Next;
		for (int i = 0; i < number; i++)
		{
			if (list[current].x == a)
				k++;
			current = list[current].Next;
		}
		printf("Найдено %d элементов\n", k);
	}
	else
	{
		printf("Список пуст");
	}
}

void main()
{
	setlocale(LC_ALL, "RUS");
	List list[N];
	list[0].Next = 0;
	for (int i = 1; i < N; i++)
	{
		list[i].Next = -1;
	}
	int select = 0;
	while (select != 6)
	{
		printf("1) Добавить элемент после заданного\n2) Добавить элемент до заданного\n3) Вывести на экран\n4) Удалить элемент\n5) Поиск элемента\n6) Выход из программы\n");
		scanf("%d", &select);
		system("cls");
		if (select == 1)
		{
			After(list);
			system("pause");
		}
		else if (select == 2)
		{
			Before(list);
			system("pause");
		}
		else if (select == 3)
		{
			Show(list);
			system("pause");
		}
		else if (select == 4)
		{
			Delete(list);
			system("pause");
		}
		else if (select == 5)
		{
			Search(list);
			system("pause");
		}
		else if (select == 6)
		{
			break;
		}
		system("cls");
	}
}