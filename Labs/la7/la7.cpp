//Программа №7 (Раздел 1, Тема 4, Номер 1) - ЛИНЕЙНЫЙ ДИНАМИЧЕСКИЙ ДВУНАПРАВЛЕННЫЙ СПИСОК

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

int number = 0;

struct List
{
	int x;
	List *Right, *Left;
};
List *list;

void Show(List *list)
{
	List *temp = list->Right;
	List *temp1 = list->Left;
	if (number == 0)
	{
		printf("Список пуст\n");
	}
	else
	{
		int ask;
		printf("1-Прямой\n2-Обратный\n");
		scanf("%d", &ask);
		if (ask == 1)
		{
			while (temp != list)
			{
				printf("%d\n", temp->x);
				temp = temp->Right;
			}
		}
		if (ask == 2)
		{
			while (temp1 != list)
			{
				printf("%d\n", temp1->x);
				temp1 = temp1->Left;
			}
		}
	}
}


void Start(List *list)
{
	system("cls");
	printf("Введите добавляемый элемент:\n");
	int a;
	scanf("%d", &a);
	List *temp = list->Right;
	List *ptemp = new List;
	ptemp->x = a;
	ptemp->Right = temp->Right;
	ptemp->Left = temp;
	temp->Right->Left = ptemp;
	temp->Right = ptemp;
	number++;
	printf("Элемент добавлен\n");
}
void After(List *list)
{
	if (number == 0)
	{
		Start(list);
	}
	else
	{
		int a;
		int b;
		int ask;
		printf("1-Прямой\n2-Обратный\n");
		scanf("%d", &ask);
		printf("Введите значение элемента, после которого вы хотите добавить\n");
		scanf("%d", &a);
		if (ask == 1) {
			List *temp = list->Right;
			do {
				if (temp->x == a)
				{
					printf("Введите значение нового элемента:\n");
					scanf("%d", &b);
					List *ptemp = new List;
					ptemp->x = b;
					ptemp->Right = temp->Right;
					ptemp->Left = temp;
					temp->Right->Left = ptemp;
					temp->Right = ptemp;
					number++;
					printf("Элемент добавлен\n");
					return;
				}
				temp = temp->Right;
			} while (temp != list);
		}
		else {
			List *temp1 = list->Left;
			do {
				if (temp1->x == a)
				{
					printf("Введите значение нового элемента:\n");
					scanf("%d", &b);
					List *ptemp = new List;
					ptemp->x = b;
					ptemp->Left = temp1->Left;
					ptemp->Right = temp1;
					temp1->Left->Right = ptemp;
					temp1->Left = ptemp;
					number++;
					printf("Элемент добавлен\n");
					return;
				}
				temp1 = temp1->Left;
			} while (temp1 != list);
		}
	}
}

void Before(List *list)
{
	if (number == 0)
	{
		Start(list);
	}
	else
	{
		int a;
		int b;
		int ask;
		printf("1-Прямой\n2-Обратный\n");
		scanf("%d", &ask);
		printf("Введите значение элемента, до которого вы хотите добавить\n");
		scanf("%d", &a);
		List *temp = list->Right;
		List *temp1 = list->Left;
		if (ask == 1)
		{
			while (temp != list)
			{
				if (temp->x == a)
				{
					printf("Введите значение нового элемента:\n");
					scanf("%d", &b);
					List *ptemp = new List;
					ptemp->x = b;
					ptemp->Left = temp->Left;
					ptemp->Right = temp;
					temp->Left->Right = ptemp;
					temp->Left = ptemp;
					number++;
					printf("Элемент добавлен\n");
					return;
				}
				temp = temp->Right;
			}
		}
		if (ask == 2)
		{
			while (temp1 != list)
			{
				if (temp1->x == a)
				{
					printf("Введите значение нового элемента:\n");
					scanf("%d", &b);
					List *ptemp = new List;
					ptemp->x = b;
					ptemp->Right = temp1->Right;
					ptemp->Left = temp1;
					temp1->Right->Left = ptemp;
					temp1->Right = ptemp;
					number++;
					printf("Элемент добавлен\n");
					return;
				}
				temp1 = temp1->Left;
			}
		}
	}
}
void Delete(List *list)
{
	if (number == 0)
	{
		printf("Список пуст.\n");
	}
	else
	{
		int a;
		int ask;
		List *temp1 = list->Left;
		List *temp = list->Right;
		printf("1-Прямой\n2-Обратный\n");
		scanf("%d", &ask);
		printf("Введите значение элемента, которое вы хотите удалить:\n");
		scanf("%d", &a);
		if (ask == 1)
		{
			while (temp != list)
			{
				if (temp->x == a)
				{
					temp->Left->Right = temp->Right;
					temp->Right->Left = temp->Left;
					delete temp;
					number--;
					printf("Элемент удалён\n");
					return;
				}
				temp = temp->Right;
			}
		}
		if (ask == 2)
		{
			while (temp1 != list)
			{
				if (temp1->x == a)
				{
					temp1->Left->Right = temp1->Right;
					temp1->Right->Left = temp1->Left;
					delete temp1;
					number--;
					printf("Элемент удалён\n");
					return;
				}
				temp1 = temp1->Left;
			}
		}
	}
}
void Search(List *list)
{
	if (number != 0)
	{
		int a;
		int ask;
		int k = 0;
		printf("Введите значение для поиска:\n");
		scanf("%d", &a);
		List *temp = list->Right;
		List *temp1 = list->Left;
		printf("1-Прямой\n2-Обратный\n");
		scanf("%d", &ask);
		if (ask == 1)
		{
			while (temp != list)
			{
				if (temp->x == a)
				{
					k++;
				}
				temp = temp->Right;
			}
		}
		if (ask == 2)
		{
			while (temp1 != list)
			{
				if (temp1->x == a)
				{
					k++;
				}
				temp1 = temp1->Left;
			}
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
	list = new List;
	list->Right = list;
	list->Left = list;
	int select = 0;
	while (select != 6)
	{
		printf("1) Добавить элемент после заданного\n2) Добавить элемент до заданного\n3) Вывести список на экран\n4) Удалить элемент\n5) Поиск элемента\n6) Выход из программы\n");
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