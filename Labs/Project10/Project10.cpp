#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>

struct Tree
{
	int Data;
	Tree* Left, * Right;
	Tree(int Data) {
		this->Data = Data;
		Left = nullptr;
		Right = nullptr;
	}
};

struct Stack
{
	int Level;
	Stack* Next;
	Tree* tree;
};

void NonRecursiveSymmetric(Tree* Root, Stack* stack)
{
	int level = -1;
	Tree* tr = Root;
	Stack* Temp;
	while (1)
	{
		while (tr != nullptr)
		{
			level++;
			Temp = new Stack;
			Temp->tree = tr;
			Temp->Level = level;
			Temp->Next = stack;
			stack = Temp;
			tr = tr->Left;
		}
		if (stack == nullptr)
		{
			return;
		}
		else
		{
			tr = stack->tree;
			level = stack->Level;
			for (int i = 0; i < stack->Level; i++)
			{
				printf("    ");
			}
			printf("%d\n", stack->tree->Data);
			Temp = stack;
			stack = stack->Next;
			delete Temp;
			tr = tr->Right;
		}
	}
}

void Direct(Tree* Root, int Level)
{
	if (Root != nullptr)
	{
		for (int i = 0; i < Level; i++)
		{
			printf("    ");
		}
		printf("%d\n", Root->Data);
		Level++;
		Direct(Root->Left, Level);
		Direct(Root->Right, Level);
	}
}


void Symmetrical(Tree* Root, int Level)
{
	if (Root != nullptr)
	{
		Level++;
		Symmetrical(Root->Left, Level);
		for (int i = 0; i < Level - 1; i++)
		{
			printf("    ");
		}
		printf("%d\n", Root->Data);
		Symmetrical(Root->Right, Level);
	}
}


void NonSymmetrical(Tree* Root, int Level)
{

	if (Root != nullptr)
	{
		Level++;
		NonSymmetrical(Root->Right, Level);
		for (int i = 0; i < Level - 1; i++)
		{
			printf("    ");
		}
		printf("%d\n", Root->Data);
		NonSymmetrical(Root->Left, Level);
	}
}

void Add(Tree** Root, int n)
{
	int N_l;
	int N_r;
	if (n == 0)
	{
		*Root = nullptr;
	}
	else
	{
		Tree* Temp = new Tree(1 + rand() % 99);
		N_l = n / 2;
		N_r = n - N_l - 1;
		Add(&Temp->Left, N_l);
		Add(&Temp->Right, N_r);
		*Root = Temp;
	}
}

void DeleteAll(Tree* Root) {
	if (Root == nullptr) return;
	DeleteAll(Root->Left);
	DeleteAll(Root->Right);
	delete Root;
	Root = nullptr;
}

void main()
{
	setlocale(LC_ALL, "RUS");
	Tree* Root = nullptr;
	Stack* stack = nullptr;
	int Act = 0;
	int n;
	while (1)
	{
		printf("1 - Создать дерево\n2 - Вывод в прямом порядке\n3 - Вывод в симметричном порядке\n4 - Вывод в обратно-симметричном порядке\n5 - Нерекурсивный вывод в симметричном порядке\n6 - Удалить дерево\n7 - Выход\n");
		int Act;
		scanf("%d", &Act);
		system("cls");
		switch (Act)
		{
		case 1:
			printf("Введите количество вершин дерева\n");
			int n;
			scanf("%d", &n);
			Add(&Root, n);
			system("pause");
			break;
		case 2:
			Direct(Root, 0);
			system("pause");
			break;
		case 3:
			Symmetrical(Root, 0);
			system("pause");
			break;
		case 4:
			NonSymmetrical(Root, 0);
			system("pause");
			break;
		case 5:
			NonRecursiveSymmetric(Root, stack);
			system("pause");
			break;
		case 6:			
			DeleteAll(Root);
			Root = nullptr;
			system("pause");
			break;
		case 7:
			return;
			break;
		default:
			break;
		}
	}
}
