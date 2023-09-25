#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

/*6 работа - динамический односвязный не кольцевой список.
Особенность - удаляемый элемент перемещается во вспомогательный список, который работает на стековом принципе.
*/

struct Node
{
	int Data;
	Node* Next;
};
Node* List; 
Node* Stack; 

void Show()
{
	if (List->Next == nullptr) {
		printf("Список пуст.\n");
		return;
	}
	Node* Current = List->Next;
	printf("Главный список:\n");
	while (Current != nullptr) {
		printf("%d\n", Current->Data);
		Current = Current->Next;
	}
}
void ShowSub()
{
	Node* Current = Stack;
	if (Current == nullptr) {
		printf("Список пуст.");
		return;
	}
	printf("Вспомогательный список:\n");
	while (Current != nullptr) {
		printf("%d\n", Current->Data);
		Current = Current->Next;
	}
}
void Start()
{
	system("cls");
	printf("Введите первый элемент:\n");
	int data;
	scanf("%d", &data);
	Node* temp = new Node;
	temp->Data = data;
	temp->Next = NULL;
	List->Next = temp;	
	printf("Элемент добавлен\n");
}
void AddAfter()
{
	if (List->Next == nullptr)
	{
		Start();
		return;
	}
	else
	{
		int Element;
		printf("Введите значение элемента, после которого вы хотите добавить\n");
		scanf("%d", &Element);
		Node* Current = List->Next;
		while(Current != nullptr)
		{
			if (Current->Data == Element)
			{
				int data;
				printf("Значение нового элемента - ");
				scanf("%d", &data);
				Node* pTemp = new Node;
				pTemp->Data = data;
				pTemp->Next = Current->Next;
				Current->Next = pTemp;
				printf("Элемент добавлен\n");
				return;
			}
			Current = Current->Next;
		}
	}
}

void AddBefore()
{
	if (List->Next == nullptr)
	{
		Start();
		return;
	}
	else {
		int Element;
		printf("Введите значение элемента, до которого вы хотите добавить элемент\n");
		scanf("%d", &Element);
		Node* Previous = List;
		Node* Current = List->Next;
		while (Current != nullptr)
		{
			if (Current->Data == Element)
			{
				int z;
				printf("Введите значение нового элемента- ");
				scanf("%d", &z);
				Node* pTemp = new Node;
				pTemp->Data = z;
				pTemp->Next = Current;
				Previous->Next = pTemp;
				return;
			}
			Previous = Previous->Next;
			Current = Current->Next;
		}
	}
}
void Delete()
{
	if (List->Next == nullptr)
	{
		printf("Список пуст.");
		return;
	}
	else
	{
		int Element;
		printf("Введите значение элемента, которое вы хотите удалить:\n");
		scanf("%d", &Element);
		Node* Current = List->Next;
		Node* Previous = List;
		while(Current != nullptr)
		{
			if (Current->Data == Element)
			{				
				Previous->Next = Current->Next;
				Current->Next = Stack;
				Stack = Current;
				return;
			}
			Current = Current->Next;
			Previous = Previous->Next;
		}
	}
}
void DeleteSubList() {
	Node* Current = Stack;
	while (Stack != nullptr) {
		Current = Current->Next;
		free(Stack);
		Stack = Current;
	}
	Stack = nullptr;
}
void Search()
{
	if (List->Next != nullptr)
	{
		int a;
		int k = 0;
		printf("Введите значение для поиска:\n");
		scanf("%d", &a);
		Node* Current = List->Next;
		while(Current != nullptr)
		{
			if (Current->Data == a) k++;
			Current = Current->Next;
		}
		printf("Найдено %d элементов\n", k);
	}
	else
	{
		printf("Список пуст\n");
		return;
	}
}

void main()
{
	setlocale(LC_ALL, "RUS");
	List = new Node;
	Stack = nullptr;
	List->Next = NULL;
	int Act = 0;
	while (1)
	{
		printf("1) Добавить элемент после заданного\n2) Добавить элемент до заданного\n3) Вывести список на экран\n4) Удалить элемент\n5) Поиск элемента\n6) Вывести вспомогательный список\n7) Очистить вспомогательный список\n8) Выход из программы\n");
		scanf("%d", &Act);
		system("cls");
		if (Act == 1)
		{
			AddAfter();
			system("pause");
		}
		else if (Act == 2)
		{
			AddBefore();
			system("pause");
		}
		else if (Act == 3)
		{
			Show();
			system("pause");
		}
		else if (Act == 4)
		{
			Delete();
			system("pause");
		}
		else if (Act == 5)
		{
			Search();
			system("pause");
		}
		else if (Act == 6)
		{
			ShowSub();
			system("pause");
		}
		else if (Act == 7)
		{
			DeleteSubList();
			system("pause");
		}
		else if (Act == 8)
		{
			return;
		}
		system("cls");
	}
}