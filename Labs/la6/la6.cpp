//Программа №6 (Раздел 1, Тема 3, Номер 5) - ЛИНЕЙНЫЙ ДИНАМИЧЕСКИЙ СПИСОК + УДАЛЕНИЕ-ПЕРЕМЕЩЕНИЕ ВО ВСПОМОГАТЕЛЬНЫЙ СПИСОК

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

const int N = 3;
int number = 0;
int numb = 0;

struct List
{
	int x;
	List *Next;
};
List *list;
List *sub;

void Show(List *list)
{
	List *temp = list;
	for (int i = 0; i < number; i++)
	{
		temp = temp->Next;
		printf("%d\n", temp->x);
	}
	if (number == 0)
	{
		printf("Список пуст\n");
	}
}

void Sub(List *list)
{
	List *temp = list;
	printf("Вспомогательный список:\n");
	for (int i = 0; i < numb; i++)
	{
		printf("%d\n", temp->x);
		temp = temp->Next;
	}
	if (numb == 0)
	{
		printf("пуст\n");
	}
}

void Start(List *list)
{
	system("cls");
	printf("Введите добавляемый элемент:\n");
	int a;
	scanf("%d", &a);
	List *temp = new List;
	temp->x = a;
	list->Next = temp;
	temp->Next = NULL;
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
		int kolvo = 0;
		printf("Введите значение элемента, после которого вы хотите добавить\n");
		scanf("%d", &a);
		List *temp = list->Next;
		for (int i = 0; i < number; i++)
		{
			if (temp->x == a)
			{
				int k;
				printf("Значение нового элемента - ");
				scanf("%d", &k);
				List *pTemp = new List;
				pTemp->x = k;
				pTemp->Next = temp->Next;
				temp->Next = pTemp;
				number++;
				printf("Элемент добавлен\n");
			}
			temp = temp->Next;
		}
	}
}

void Before(List *list)
{
	if (number == 0)
	{
		Start(list);
	}
	else {
		int a;
		int kolvo = 0;
		printf("Введите значение элемента, до которого вы хотите добавить элемент\n");
		scanf("%d", &a);
		List *last = list;
		List *temp = list->Next;
		for (int i = 0; i < number; i++)
		{
			if (temp->x == a)
			{
				int z;
				printf("Введите значение нового элемента- ");
				scanf("%d", &z);
				List *newtemp = new List;
				newtemp->x = z;
				newtemp->Next = temp;
				last->Next = newtemp;
				number++;
				return;
			}
			last = last->Next;
			temp = temp->Next;
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
		printf("Введите значение элемента, которое вы хотите удалить:\n");
		scanf("%d", &a);
		List *temp = list->Next;
		List *p = list;
		for (int i = 0; i < number; i++)
		{
			if (temp->x == a)
			{
				List *del = temp->Next;
				p->Next = del;
				number--;
				temp->Next = sub;
				sub = temp;
				numb++;
				break;
			}
			temp = temp->Next;
			p = p->Next;
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
		List *temp = list->Next;
		for (int i = 0; i < number; i++)
		{
			if (temp->x == a)
				k++;
			temp = temp->Next;
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
	sub = new List;
	sub->Next = NULL;
	list->Next = NULL;
	int select = 0;
	while (select != 7)
	{
		printf("1) Добавить элемент после заданного\n2) Добавить элемент до заданного\n3) Вывести список на экран\n4) Удалить элемент\n5) Поиск элемента\n6) Вывести вспом.список\n7) Выход из программы\n");
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
			Sub(sub);
			system("pause");
		}
		else if (select == 7)
		{
			break;
		}
		system("cls");
	}
}