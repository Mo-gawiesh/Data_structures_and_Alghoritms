//Программа №10 (Раздел 1, Тема 5, Номер 2) - ИДЕАЛЬНО СБАЛАНСИРОВАННОЕ ДВОИЧНОЕ ДЕРЕВО С НЕРЕКУРСИВНЫМ ВАРИАНТОМ СИММЕТРИЧНОГО ОБХОДА (ВСПОМОГАТЕЛЬНЫЙ СТЕК)
//СОЗДАЕМ ВСПОМОГАТЕЛЬНЫЙ СТЕК ДЛЯ ХРАНЕНИЯ ПОСЛЕДОВАТЕЛЬНОСТИ ПРОЙДЕННЫХ ВЕРШИН ОТ КОРНЯ ДО ТЕКУЩЕЙ ВЕРШИНЫ И УРОВНЯ ЭТИХ ВЕРШИН В ДЕРЕВЕ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
int n;
struct Tree
{
	int inf;
	Tree *Left, *Right;
};
Tree *Root;
struct Stack
{
	int i;
	Stack *Next;
	Tree *t;
};
Stack *stack;

void Direct(Tree *el, int level)
{
	if (el != NULL)
	{
		for (int i = 0; i < level; i++)
		{
			printf("    ");
		}
		printf("%d\n", el->inf);
		level++;
		Direct(el->Left, level);
		Direct(el->Right, level);
	}
}

void Symmetr(Tree *el, int level)
{
	if (el != NULL)
	{
		level++;
		Symmetr(el->Left, level);
		for (int i = 0; i < level - 1; i++)
		{
			printf("    ");
		}
		printf("%d\n", el->inf);
		Symmetr(el->Right, level);
	}
}

void Back_Symmetr(Tree *el, int level)
{

	if (el != NULL)
	{
		level++;
		Back_Symmetr(el->Right, level);
		for (int i = 0; i < level - 1; i++)
		{
			printf("    ");
		}
		printf("%d\n", el->inf);
		Back_Symmetr(el->Left, level);
	}
}

void AddTree(Tree **el, int n)
{
	int N_l;
	int N_r;
	if (n == 0)
	{
		*el = NULL;
	}
	else
	{
		Tree *Temp = new (Tree);
		Temp->inf = 1 + rand() % 99;
		N_l = n / 2;
		N_r = n - N_l - 1;
		AddTree(&Temp->Left, N_l);
		AddTree(&Temp->Right, N_r);
		*el = Temp;
	}
}
void Notrec(Tree *Root)
{
	int level = -1;
	Tree *el = Root;
	Stack *Temp;
	bool Stop = false;
	while (!(Stop))
	{
		while (el != NULL)
		{
			level++;
			Temp = new Stack;
			Temp->t = el;
			Temp->i = level;
			Temp->Next = stack;
			stack = Temp;
			el = el->Left;
		}
		if (stack == NULL)
		{
			Stop = true;
		}
		else
		{
			el = stack->t;
			level = stack->i;
			for (int i = 0; i < stack->i; i++)
			{
				printf("    ");
			}
			printf("%d\n", el->inf);
			Temp = stack;
			stack = stack->Next;
			delete Temp;
			el = el->Right;
		}
	}
}

void main()
{
	setlocale(LC_ALL, "RUS");
	Tree *Root = new Tree;
	Root = NULL;
	int select = 0;
	while (select != 6)
	{
		printf("1. Построение дерева\n2. Вывод дерева в прямом порядке\n3. Вывод дерева в симметричном порядке\n4. Вывод дерева в обратно-симметричном порядке\n5. Нерекурсивный симметричный вывод.\n6. Выход.\n");
		scanf("%d", &select);
		system("cls");
		if (select == 1)
		{
			printf("Введите количество вершин дерева\n");
			scanf("%d", &n);
			AddTree(&Root, n);
			system("pause");
		}
		else if (select == 2)
		{
			Direct(Root, 0);
			system("pause");
		}
		else if (select == 3)
		{
			Symmetr(Root, 0);
			system("pause");
		}
		else if (select == 4)
		{
			Back_Symmetr(Root, 0);
			system("pause");
		}
		else if (select == 5)
		{
			Notrec(Root);
			system("pause");
		}
		else if (select == 6)
		{
			break;
		}
		system("cls");
	}
}
