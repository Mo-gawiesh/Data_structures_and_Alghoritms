//Программа №11 (Раздел 1, Тема 5, Номер 3) - ОБРАБОТКА ПРОИЗВОЛЬНЫХ ДВОИЧНЫХ ДЕРЕВЬЕВ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct Tree {
	int inf;
	Tree *Left;
	Tree *Right;
};
Tree *tree = NULL;
Tree *parent = NULL;
bool stop = false;
int k = 0;

void Search(Tree *tree, int txt) {
	if (stop == true) {
		return;
	}
	if (tree != NULL) {
		if (tree->inf == txt) {
			stop = true;
			parent = tree;
			return;
		}
		Search(tree->Left, txt);
		Search(tree->Right, txt);
	}
}

void Add()
{
	int a;
	if (tree == NULL)
	{
		tree = new Tree;
		printf("Введите инф. часть вершины:\n");
		scanf("%d", &a);
		tree->inf = a;
		tree->Left = NULL;
		tree->Right = NULL;
	}
	else
	{
		int inf;
		printf("Введите родительскую вершину для элемента:\n");
		scanf("%d", &inf);
		parent = NULL;
		stop = false;
		Search(tree, inf);
		if (parent != NULL)
		{
			printf("Введите инф. часть элемента, которого хотите добавить:\n");
			Tree *current = new Tree;
			scanf("%d", &current->inf);
			current->Right = NULL;
			current->Left = NULL;
			if (parent->Left == NULL && parent->Right == NULL)
			{
				int select;
				printf("1)Добавить как левого потомка.\n2)Добавить как правого потомка.\n");
				scanf("%d", &select);
				if (select == 1)
				{
					parent->Left = current;
				}
				else if (select == 2)
				{
					parent->Right = current;
				}
			}
			else
			{
				if (parent->Left == NULL)
				{
					printf("Добавлена левая вершина.\n");
					parent->Left = current;
				}
				else if (parent->Right == NULL)
				{
					printf("Добавлена правая вершина.\n");
					parent->Right = current;
				}
				else
				{
					printf("Вершина не может быть добавлена. Слишком много потомков.\n");
					return;
				}
			}

		}
		else
		{
			printf("Родительский элемент не найден\n");
			return;
		}
	}
	k++;
}

void ReverseSymmetry(Tree *head, int level)
{
	if (head != NULL)
	{
		(level)++;
		ReverseSymmetry(head->Left, level);
		for (int i = 0; i < 4 * (level - 1); i++)
		{
			printf(" ");
		}
		printf("%d\n", head->inf);
		ReverseSymmetry(head->Right, level);
	}
}

void Delete(Tree *&head)
{
	if (head != NULL)
	{
		Delete(head->Left);
		Delete(head->Right);
		free(head);
		k--;
		if (k == 0)
		{
			head = NULL;
		}
	}
}
void main()
{
	setlocale(LC_ALL, "rus");
	int select = 0;
	while (select != 5)
	{
		printf("1)Добавить элемент.\n2)Поиск.\n3)Вывод дерева(обратно-симметричный).\n4)Удалить дерево.\n5)Выход.\n");
		scanf("%d", &select);
		if (select == 1)
		{
			Add();
			system("pause");
		}
		else if (select == 2)
		{
			if (tree != NULL)
			{
				printf("Введите элемент для поиска:\n");
				int find;
				scanf("%d", &find);
				parent = NULL;
				stop = false;
				Search(tree, find);
				if (parent != NULL)
				{
					printf("Элемент найден\n");
				}
				else
				{
					printf("элемент не найден\n");
				}
			}
			else
			{
				printf("Дерево пустое\n");
			}
			system("pause");
		}
		else if (select == 3)
		{
			if (tree != NULL)
			{
				ReverseSymmetry(tree, 0);
			}
			else
			{
				printf("Ничего нет\n");
			}
			system("pause");
		}
		else if (select == 4)
		{
			Delete(tree);
			printf("Дерево удалено\n");
			system("pause");
		}
		else if (select == 5)
		{
			break;
		}
		system("cls");
	}
}