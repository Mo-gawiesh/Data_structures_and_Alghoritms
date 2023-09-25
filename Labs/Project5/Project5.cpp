#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>


const int N = 5;
int Counter = 0;

struct Node
{
	int Data;
	int Next;
};
void Show(Node* list)
{
	int current = list[0].Next;
	for (int i = 0; i < Counter; i++)
	{
		printf("%d\n", list[current].Data);
		current = list[current].Next;
	}
	if (Counter == 0)
	{
		printf("Список пуст\n");
	}
}
int SearchInd(Node* list)
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
void SetFirst(Node* list)
{
	system("cls");
	printf("Введите новый элемент:\n");
	int value;
	scanf("%d", &value);
	list[1].Next = list[0].Next;
	list[0].Next = 1;
	Counter++;
	list[1].Data = value;
	printf("Элемент добавлен\n");
}
void After(Node* list)
{
	int k = SearchInd(list);
	if (k != 0)
	{
		if (Counter == 0)
		{
			SetFirst(list);
		}
		else {
			int Element;
			printf("Введите значение элемента, после которого вы хотите добавить\n");
			scanf("%d", &Element);
			int current = list[0].Next;
			for (int i = 0; i < Counter; i++)
			{
				if (list[current].Data == Element)
				{
					if (Counter < N)
					{
						int data;
						printf("Значение нового элемента - ");
						scanf("%d", &data);
						list[k].Data = data;
						list[k].Next = list[current].Next;
						list[current].Next = k;
						Counter++;
						printf("Элемент добавлен\n");
					}
					else {
						printf("Список заполнен!\n");
						return;
					}
				}
				current = list[current].Next;
			}
		}
	}
	else {
		printf("Список заполнен!\n");
	}
}
void Before(Node* list)
{
	int k = SearchInd(list);
	if (k != 0)
	{
		if (Counter == 0)
		{
			SetFirst(list);
		}
		else {
			int Element;
			printf("Введите значение элемента, до которого вы хотите добавить элемент\n");
			scanf("%d", &Element);
			int current = list[0].Next;
			int last = 0;
			for (int i = 0; i < Counter; i++)
			{
				if (list[current].Data == Element)
				{
					if (Counter < N)
					{
						int data;
						printf("Введите значение нового элемента- ");
						scanf("%d", &data);
						list[k].Next = current;
						list[last].Next = k;
						list[k].Data = data;
						Counter++;
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
void Delete(Node* list)
{
	if (Counter == 0)
	{
		printf("Список пуст.\n");
	}
	else {
		int data;
		printf("Введите значение элемента, которое вы хотите удалить:\n");
		scanf("%d", &data);
		int current = list[0].Next;
		int last = 0;
		for (int i = 0; i < Counter; i++)
		{
			if (list[current].Data == data)
			{
				list[last].Next = list[current].Next;
				list[current].Next = -1;
				Counter--;
				printf("Элемент удалён!\n");
				break;
			}
			current = list[current].Next;
			last = list[last].Next;
		}
	}
}
void Search(Node* list)
{
	if (Counter != 0)
	{
		int a;
		int k = 0;
		printf("Введите значение для поиска:\n");
		scanf("%d", &a);
		int current = list[0].Next;
		for (int i = 0; i < Counter; i++)
		{
			if (list[current].Data == a) k++;
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
	Node list[N + 1];
	list[0].Next = 0;
	for (int i = 1; i < N; i++)
	{
		list[i].Next = -1;
	}
	int Act = 0;
	while (Act != 6)
	{
		printf("1) Добавить элемент после заданного\n2) Добавить элемент до заданного\n3) Вывод\n4) Удалить элемент\n5) Поиск элемента\n6) Выход из программы\n");
		scanf("%d", &Act);
		system("cls");
		if (Act == 1)
		{
			After(list);
			system("pause");
		}
		else if (Act == 2)
		{
			Before(list);
			system("pause");
		}
		else if (Act == 3)
		{
			Show(list);
			system("pause");
		}
		else if (Act == 4)
		{
			Delete(list);
			system("pause");
		}
		else if (Act == 5)
		{
			Search(list);
			system("pause");
		}
		else if (Act == 6)
		{
			break;
		}
		system("cls");
	}
}