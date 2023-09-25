#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

struct Tree
{
	int Data;
	int Counter;
	Tree* Left, * Right;
	Tree(int Data) {
		this->Data = Data;
		Counter = 1;
		Left = nullptr;
		Right = nullptr;
	}
};

void NonSymmetrical(Tree* Root, int Level);
void LinewiseShow(Tree* Root);
void Delete(Tree*& Root, int data);
void Changer(Tree*& Current, Tree*& PTemp);
int Search(Tree* Root, int data);
void Add(Tree** Root, int data);

int Search(Tree* Root, int data) {
	Tree* Current = Root;
	while (Current != nullptr) {
		if (Current->Data == data) return Current->Counter;
		else if (Current->Data > data) Current = Current->Left;
		else if (Current->Data < data) Current = Current->Right;
	}
	return 0;
}

void Add(Tree** Root, int data) {
	if ((*Root) == nullptr) {
		(*Root) = new Tree(data);
		return;
	}
	if ((*Root)->Data > data) Add(&(*Root)->Left, data);
	else if ((*Root)->Data < data) Add(&(*Root)->Right, data);
	else (*Root)->Counter++;
}

void AddNonRecursive(Tree*& tree, int data)
{
	if (tree == NULL)
	{
		tree = new Tree(data);
		return;
	}
	else
	{
		Tree* parent = tree;
		Tree* current = tree;
		while (current != NULL)
		{
			parent = current;
			if (data > current->Data)
			{
				current = current->Right;
			}
			else
			{
				if (data < current->Data)
				{
					current = current->Left;
				}
				else
				{
					current->Counter++;
					current = nullptr;
				}
			}
		}
		if (data > parent->Data)
		{
			parent->Right = new Tree(data);
		}
		else if (data < parent->Data)
		{
			parent->Left = new Tree(data);
		}
	}
}
void NonSymmetrical(Tree* Root, int Level)
{

	if (Root != NULL)
	{
		Level++;
		NonSymmetrical(Root->Right, Level);
		for (int i = 0; i < Level - 1; i++)
		{
			printf("    ");
		}
		printf("%d(%d)\n", Root->Data, Root->Counter);
		NonSymmetrical(Root->Left, Level);
	}
}

void LinewiseShow(Tree* Root) {
	if (Root == nullptr) return;
	LinewiseShow(Root->Left);
	printf(" %d(%d) ", Root->Data, Root->Counter);
	LinewiseShow(Root->Right);
}

void Delete(Tree*& Root, int data) {
	if (Root != nullptr)
	{
		if (data < Root->Data)
		{
			Delete(Root->Left, data);
		}
		else
		{
			if (data > Root->Data)
			{
				Delete(Root->Right, data);
			}
			else
			{
				Tree* temp = Root;
				if (temp->Right == NULL)
				{
					Root = temp->Left;
				}
				else
				{
					if (temp->Left == NULL)
					{
						Root = temp->Right;
					}
					else
					{
						Changer(temp->Left, temp);
					}
				}
				delete temp;
				temp = nullptr;
			}
		}
	}
}

void Changer(Tree*& current, Tree*& temp)
{
	if (current->Right != nullptr)
	{
		Changer(current->Right, temp);
	}
	else
	{
	
		temp->Data = current->Data;
		temp = current;
		current = current->Left;
	}
}

void DeleteAll(Tree* Root) {
	if (Root == nullptr) return;
	DeleteAll(Root->Left);
	DeleteAll(Root->Right);
	delete Root;
	Root = nullptr;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	Tree* Root = nullptr;
	int Act = 0;
	int n;
	while (1)
	{
		printf("1 - Добавить несколько вершин\n2 - Добавить вершину\n3 - Вывод в строку\n4 - Вывод в обратно-симметричном порядке\n5 - Поиск вершины\n6 - Удалить вершину\n7 - Удалить дерево\n8 - Выход\n");
		scanf("%d", &Act);
		system("cls");
		switch (Act)
		{
		case 1:
			printf("Введите количество вершин: ");
			scanf("%d", &Act);
			for (int i = 0; i < Act; i++) {
				Add(&Root, rand() % 100 + 1);
			}
			system("pause");
			break;
		case 2:
			printf("Введите элемент: ");
			scanf("%d", &n);
			AddNonRecursive(Root, n);
			system("pause");
			break;
		case 3:
			LinewiseShow(Root);
			system("pause");
			break;
		case 4:
			NonSymmetrical(Root, 0);
			system("pause");
			break;
		case 5:
			if (Root == nullptr) {
				printf("Дерево пустое\n");
				system("pause");
				break;
			}
			printf("Введите элемент для поиска: ");
			scanf("%d", &n);
			n = Search(Root, n);
			if (n != 0) {
				printf("Элемент найден, число повторений - %d\n", n);
			}
			else {
				printf("Элемент не найден.\n");
			}
			system("pause");
			break;
		case 6:
			printf("Введите элемент для удаления: ");
			scanf("%d", &n);
			Delete(Root, n);
			system("pause");
			break;
		case 7:
			DeleteAll(Root);
			Root = nullptr;
			system("pause");
			break;
		case 8:
			return 0;
			break;
		default:
			break;
		}
	}
}
