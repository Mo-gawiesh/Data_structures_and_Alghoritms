//Программа №9 (Раздел 1, Тема 5, Номер 1) - ИДЕАЛЬНО СБАЛАНСИРОВАННОЕ ДВОИЧНОЕ ДЕРЕВО

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

void BackSymmetr(Tree *el, int level)
{

	if (el != NULL)
	{
		level++;
		BackSymmetr(el->Right, level);
		for (int i = 0; i < level - 1; i++)
		{
			printf("    ");
		}
		printf("%d\n", el->inf);
		BackSymmetr(el->Left, level);
	}
}

void Add(Tree **el, int n)
{
	int N_l;
	int N_r;
	if (n == 0)
	{
		*el = NULL;
	}
	else
	{
		Tree *Temp = new Tree;
		Temp->inf = 1 + rand() % 99;
		N_l = n / 2;
		N_r = n - N_l - 1;
		Add(&Temp->Left, N_l);
		Add(&Temp->Right, N_r);
		*el = Temp;
	}
}

void main()
{
	setlocale(LC_ALL, "RUS");
	Tree *Root = new Tree;
	Root = NULL;
	int select = 0;
	while (select != 5)
	{
		printf("1. Создать дерево\n2. Вывод в прямом порядке\n3. Вывод в симметричном порядке\n4. Вывод в обратно-симметричном порядке\n5. Выход\n");
		scanf("%d", &select);
		system("cls");
		if (select == 1)
		{
			printf("Введите количество вершин дерева\n");
			scanf("%d", &n);
			Add(&Root, n);
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
			BackSymmetr(Root, 0);
			system("pause");
		}
		else if (select == 5)
		{
			break;
		}
		system("cls");
	}
}
