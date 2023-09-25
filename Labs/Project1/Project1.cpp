#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

struct Node {
	int data;
	Node* next;
};

void Push(Node** stack, int value)
{	
	Node* current = (Node*)malloc(sizeof(Node));
	current->data = value;
	current->next = (*stack);
	(*stack) = current;
}

void PushFromDel(Node** stack, Node** deleted)
{
	if ((*deleted) == NULL)
	{
		printf("Вспомогательный стек пуст!");
		return;
	}
	Node* current = NULL;
	current = (*deleted);
	(*deleted) = (*deleted)->next;
	current->next = (*stack);
	(*stack) = current;
}
Node* PushMany(Node* stack)
{
	int count = 0;
	printf("Введите кол-во элементов:\n");
	while (!scanf("%d", &count))
	{
		while (getchar() != '\n')
			printf("Введите кол-во элементов:\n");
	}
	srand(time(NULL));
	while (count != 0)
	{
		int i = rand() % 100;
		Push(&stack, i);
		count--;
	}
	return stack;
}

void Show(Node* stack)
{
	if (stack == NULL)
	{
		printf("Стек пуст!");
		return;
	}
	Node* current = NULL;
	current = stack;
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
	free(current);
}

void Pop(Node** stack, Node** deleted)
{
	if ((*stack) == NULL)
	{
		printf("Стек пуст!");
		return;
	}
	printf("1 - Удалить безвозвратно\n2 - Поместить в вспомогательный стек\n");
	int select = 0;
	while (!scanf("%d", &select))
	{
		while (getchar() != '\n')
			printf("Введите заново\n");
	}
	if (select == 1)
	{
		Node* current = (*stack)->next;
		free(*stack);
		(*stack) = current;
		return;
	}
	else if (select == 2)
	{
		Node* current;
		current = (*stack)->next;
		(*stack)->next = *deleted;
		(*deleted) = (*stack);
		(*stack) = current;
		return;
	}
	else
	{
		printf("Неверное значение, попробуйте заново!");
		return;
	}
}

void Destroy(Node* stack)
{
	Node* Current = stack;
	while (Current != nullptr) {
		free(stack);
		Current = Current->next;
		stack = Current;
	}
	stack = NULL;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int select = 0;
	Node* stack = NULL;
	Node* deleted = NULL;

	while (true)
	{
		printf("Выберите действие:\n1 - Ввести элемент\n2 - Удалить элемент\n3 - Вывести основной стек\n4 - Вывести вспомогательный стек\n5 - Выход\n");
		while (!scanf("%d", &select))
		{
			while (getchar() != '\n')
				printf("Введите заново\n");
		}
		if (select == 1)
		{
			system("cls");
			printf("1 - Один\n2 - Несколько\n");
			while (!scanf("%d", &select))
			{
				while (getchar() != '\n')
					printf("1 - Один\n2 - Несколько\n");
			}
			if (select == 1)
			{
				system("cls");
				printf("Выберите:\n1 - Ввести  значение\n2 - Из вспомогательного стека\n");
				while (!scanf("%d", &select))
				{
					while (getchar() != '\n')
						printf("Введите заново\n");
				}
				if (select == 1)
				{
					system("cls");
					printf("Введите значение: ");
					while (!scanf("%d", &select))
					{
						while (getchar() != '\n')
							printf("Введите значение: ");
					}
					Push(&stack, select);
				}
				else if (select == 2)
				{
					system("cls");
					PushFromDel(&stack, &deleted);
				}
				else
				{
					printf("Неверное значение!\n");
				}
			}
			else if (select == 2)
			{
				system("cls");
				stack = PushMany(stack);
			}
			else
			{
				printf("Неверное значение!\n");
			}
		}
		else if (select == 2)
		{
			system("cls");
			Pop(&stack, &deleted);
		}
		else if (select == 3)
		{
			system("cls");
			Show(stack);
		}
		else if (select == 4)
		{
			system("cls");
			Show(deleted);
		}
		else if (select == 5)
		{
			Destroy(stack);
			Destroy(deleted);
			break;
		}
		system("pause");
		system("cls");
	}
	system("pause");
}
