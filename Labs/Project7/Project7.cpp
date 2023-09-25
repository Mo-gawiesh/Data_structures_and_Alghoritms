#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

/*7 работа - динамический двусвязный кольцевой список.
Особенности - список должен иметь заголовок и быть кольцевым + можно выбирать порядок обхода: прямой/обратный.
При прямом порядке - обход идет по правым указателям.
При обратном - по левым указателям.*/

struct Node
{
	int Data;
	Node* Right, * Left;
};

Node* List;

void Show()
{
	system("cls");
	Node* Current = List->Right;
	if (List->Right == List)
	{
		printf("Список пуст\n");
		return;
	}
	else
	{
		int Act;
		printf("1-Прямой\n2-Обратный\n");
		scanf("%d", &Act);
		printf("\n");
		if (Act == 1)
		{
			while (Current != List)
			{
				printf("%d\n", Current->Data);
				Current = Current->Right;
			}
		}
		if (Act == 2)
		{
			Current = List->Left;
			while (Current != List)
			{
				printf("%d\n", Current->Data);
				Current = Current->Left;
			}
		}
	}
}


void SetFirst()
{
	system("cls");
	printf("Введите добавляемый элемент:\n");
	int data;
	scanf("%d", &data);
	Node* ptemp = new Node;
	ptemp->Data = data;
	ptemp->Right = List;
	ptemp->Left = List;
	List->Left = ptemp;
	List->Right = ptemp;
	printf("Элемент добавлен.\n");
}

void After()
{
	if (List->Right == List)
	{
		SetFirst();
		return;
	}
	else
	{
		int Element;
		int Act;
		int data;
		printf("1-Прямой\n2-Обратный\n");
		scanf("%d", &Act);
		printf("Введите значение элемента, после которого вы хотите добавить\n");
		scanf("%d", &Element);
		if (Act == 1) {
			Node* Current = List->Right;
			do {
				if (Current->Data == Element)
				{
					printf("Введите значение нового элемента:\n");
					scanf("%d", &data);
					Node* ptemp = new Node;
					ptemp->Data = data;
					ptemp->Right = Current->Right;
					ptemp->Left = Current;
					Current->Right->Left = ptemp;
					Current->Right = ptemp;
					printf("Элемент добавлен\n");
					return;
				}
				Current = Current->Right;
			} while (Current != List);
		}
		else {
			Node* Current = List->Left;
			do {
				if (Current->Data == Element)
				{
					printf("Введите значение нового элемента:\n");
					scanf("%d", &data);
					Node* ptemp = new Node;
					ptemp->Data = data;
					ptemp->Left = Current->Left;
					ptemp->Right = Current;
					Current->Left->Right = ptemp;
					Current->Left = ptemp;
					printf("Элемент добавлен\n");
					return;
				}
				Current = Current->Left;
			} while (Current != List);
		}
	}
}

void Before()
{
	if (List->Right == List)
	{
		SetFirst();
	}
	else
	{
		int Element;
		int data;
		int Act;
		printf("1-Прямой\n2-Обратный\n");
		scanf("%d", &Act);
		printf("Введите значение элемента, до которого вы хотите добавить\n");
		scanf("%d", &Element);
		Node* Current = List->Right;
		if (Act == 1)
		{
			Current = List->Right;
			while (Current != List)
			{
				if (Current->Data == Element)
				{
					printf("Введите значение нового элемента:\n");
					scanf("%d", &data);
					Node* ptemp = new Node;
					ptemp->Data = data;
					ptemp->Left = Current->Left;
					ptemp->Right = Current;
					Current->Left->Right = ptemp;
					Current->Left = ptemp;
					printf("Элемент добавлен\n");
					return;
				}
				Current = Current->Right;
			}
		}
		if (Act == 2)
		{
			Current = List->Left;
			while (Current != List)
			{
				if (Current->Data == Element)
				{
					printf("Введите значение нового элемента:\n");
					scanf("%d", &data);
					Node* ptemp = new Node;
					ptemp->Data = data;
					ptemp->Right = Current->Right;
					ptemp->Left = Current;
					Current->Right->Left = ptemp;
					Current->Right = ptemp;
					printf("Элемент добавлен\n");
					return;
				}
				Current = Current->Left;
			}
		}
	}
}
void Delete()
{
	if (List->Right == List)
	{
		printf("Список пуст.\n");
	}
	else
	{
		int data;
		int ask;
		Node* temp1 = List->Left;
		Node* temp = List->Right;
		printf("1-Прямой\n2-Обратный\n");
		scanf("%d", &ask);
		printf("Введите значение элемента, которое вы хотите удалить:\n");
		scanf("%d", &data);
		if (ask == 1)
		{
			while (temp != List)
			{
				if (temp->Data == data)
				{
					temp->Left->Right = temp->Right;
					temp->Right->Left = temp->Left;
					delete temp;
					printf("Элемент удалён\n");
					return;
				}
				temp = temp->Right;
			}
		}
		if (ask == 2)
		{
			while (temp1 != List)
			{
				if (temp1->Data == data)
				{
					temp1->Left->Right = temp1->Right;
					temp1->Right->Left = temp1->Left;
					delete temp1;
					printf("Элемент удалён\n");
					return;
				}
				temp1 = temp1->Left;
			}
		}
	}
}
void Search()
{
	if (List->Right != List)
	{
		int a;
		int ask;
		int k = 0;
		printf("Введите значение для поиска:\n");
		scanf("%d", &a);
		Node* temp = List->Right;
		Node* temp1 = List->Left;
		printf("1-Прямой\n2-Обратный\n");
		scanf("%d", &ask);
		if (ask == 1)
		{
			while (temp != List)
			{
				if (temp->Data == a)
				{
					k++;
				}
				temp = temp->Right;
			}
		}
		if (ask == 2)
		{
			while (temp1 != List)
			{
				if (temp1->Data == a)
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
	List = new Node;
	List->Right = List;
	List->Left = List;
	int select = 0;
	while (select != 6)
	{
		printf("1) Добавить элемент после заданного\n2) Добавить элемент до заданного\n3) Вывести список на экран\n4) Удалить элемент\n5) Поиск элемента\n6) Выход из программы\n");
		scanf("%d", &select);
		system("cls");
		if (select == 1)
		{
			After();
			system("pause");
		}
		else if (select == 2)
		{
			Before();
			system("pause");
		}
		else if (select == 3)
		{
			Show();
			system("pause");
		}
		else if (select == 4)
		{
			Delete();
			system("pause");
		}
		else if (select == 5)
		{
			Search();
			system("pause");
		}

		else if (select == 6)
		{
			break;
		}
		system("cls");
	}
}