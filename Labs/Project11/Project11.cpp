#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <sstream>

/*11 работа - необходимо реализовать программу для работы с произвольными двоичными деревьями
Необходимы:
•	поиск вершины с заданным значением информационной части
•	добавление левого или правого потомка для заданной вершины
•	построчный вывод дерева с помощью основных правил обхода
•	уничтожение всего дерева
*/

struct Tree
{
	int Data;
	Tree* Left;
	Tree* Right;
	Tree(int Data) {
		this->Data = Data;
		Left = nullptr;
		Right = nullptr;
	}
};

bool HasData = false;
Tree* ParentNode; 

void NonSymmetrical(Tree* Root, int Level);
void Search(Tree* Root, int data);
void Add(Tree** Root);
void DeleteTree(Tree* Root);

void Search(Tree* Root, int data) {
	if (HasData) {
		return;
	}
	if (Root != nullptr) {
		if (Root->Data == data) {
			HasData = true;
			ParentNode = Root;
			return;
		}
		Search(Root->Left, data);
		Search(Root->Right, data);
	}
}

void Add(Tree** Root) {
	int data;
	if (*Root == nullptr) {
		printf("Введите значение корневой вершины дерева: ");		
		scanf("%d", &data);
		*Root = new Tree(data);
		return;
	}
	HasData = false;
	ParentNode = nullptr;
	printf("Введите значение вершины, в которую нужно добавить: ");
	scanf("%d", &data);
	Search(*Root, data);
	if (HasData && ParentNode != nullptr) {
		if (ParentNode->Left == nullptr && ParentNode->Right == nullptr) {
			int Act;
			printf("Оба потомка пустые. Добавить:\n1 - Левого потомка\n2 - Правого потомка\n");
			scanf("%d", &Act);
			if (Act == 1) {
				printf("Введите информационную часть: ");
				scanf("%d", &data);
				ParentNode->Left = new Tree(data);
				return;
			}
			else if (Act == 2) {
				printf("Введите информационную часть: ");
				scanf("%d", &data);
				ParentNode->Right = new Tree(data);
				return;
			}
			else return;
		}
		else if (ParentNode->Left == nullptr && ParentNode->Right != nullptr) {	
			printf("Можно добавить только левого потомка, введите информационную часть: ");
			scanf("%d", &data);
			ParentNode->Left = new Tree(data);
		}
		else if(ParentNode->Left!=nullptr && ParentNode->Right == nullptr){
			printf("Можно добавить только правого потомка, введите информационную часть: ");
			scanf("%d", &data);
			ParentNode->Right = new Tree(data);
		}
		else {
			printf("Добавление невозможно, оба потомка существуют.\n");
			return;
		}
		printf("Элемент успешно добавлен.\n");
	}
	else {
		printf("Элемент не найден.\n");
		return;
	}

}

void DeleteTree(Tree* Root) {
	if (Root == nullptr) return;
	DeleteTree(Root->Left);
	DeleteTree(Root->Right);
	delete Root;
	Root = nullptr;
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

void main()
{
	setlocale(LC_ALL, "RUS");
	Tree* Root = nullptr;
	int Act = 0;
	int n;
	while (1)
	{
		int Act;
		printf("1 - Добавить вершину\n2 - Вывод в обратно-симметричном порядке\n3 - Поиск\n4 - Удалить дерево\n5 - Выход\n");
		scanf("%d", &Act);
		system("cls");
		switch (Act)
		{
		case 1:			
			Add(&Root);
			system("pause");
			break;
		case 2:
			NonSymmetrical(Root, 0);
			system("pause");
			break;
		case 3:			
			ParentNode = nullptr;
			HasData = false;
			printf("Введите элемент для поиска: ");
			scanf("%d", &Act);
			Search(Root, Act);
			if (HasData) {
				printf("Элемент найден.\n");
			}
			else {
				printf("Элемент не найден.\n");
			}
			system("pause");
			break;
		case 4:
			DeleteTree(Root);
			Root = nullptr;
			system("pause");
			break;
		case 5:
			return;
			break;
		default:
			break;
		}
	}
}
