#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct LItem
{
	char* key;
	LItem* left;
	LItem* right;
	LItem(char* data) {
		key = data;
		left = NULL;
		right = NULL;
	}
};
struct List
{
	LItem* head;
	LItem* last;
};

void AddKey(List** list, char* key)
{
	if (*list == NULL)
	{
		*list = (List*)malloc(sizeof(List));
		(*list)->last = new LItem(key);
		(*list)->last->left = NULL;
		(*list)->last->right = NULL;
		(*list)->head = (*list)->last;
	}
	else
	{
		LItem* oldTail = (*list)->last;
		(*list)->last = new LItem(key);
		(*list)->last->left = NULL;
		(*list)->last->right = oldTail;
		oldTail->left = (*list)->last;
	}
}

int Search(List* list, char* key, int index)
{
	if (list != NULL)
	{
		int count = 0;
		LItem* cur = list->head;
		while (cur != NULL)
		{
			count++;
			if (!strcmp(cur->key, key))
			{
				printf("Элемент существует\nИндекс: %d Ключ: %s\nСравнений: %d\n", index, cur->key, count);
				return 1;
			}
			else
			{
				cur = cur->left;
			}
		}
	}
	return 0;
}

void Show(List* list, int index)
{
	if (list != NULL)
	{
		LItem* cur = list->head;
		while (cur != NULL)
		{
			printf("Индекс: %d Ключ: %s\n", index, cur->key);
			cur = cur->left;
		}
	}
}
int Hash(char* word, int m)
{
	int sum = 0;
	for (int i = 0; i < strlen(word); i++)
	{
		sum += (int)word[i];
	}
	return sum % m;
}

void main()
{
	setlocale(LC_ALL, "RUS");
	int size, select = 0;
	printf("Введите размер таблицы.\n");
	scanf("%d", &size);
	List** table = (List**)malloc(size * sizeof(List*));
	for (int i = 0; i < size; i++)
	{
		table[i] = NULL;
	}
	while (select != 5)
	{
		printf("1 - Добавить ключ\n2 - Удалить ключ\n3 - Поиск\n4 - Вывод\n5 - Выход\n");
		scanf("%d", &select);
		if (select == 1)
		{
			char* key = (char*)malloc(256 * sizeof(char));
			printf("Введите ключ: \n");
			scanf("%s", key);
			int index = Hash(key, size);
			if (Search(table[index], key, index) != 0)
			{
				continue;
			}
			AddKey(&table[index], key);
		}
		else if (select == 2)
		{
			char* key = (char*)malloc(256 * sizeof(char));
			printf("Введите ключ: \n");
			scanf("%s", key);
			int index = Hash(key, size);
			if (table[index] != NULL)
			{
				LItem* cur = table[index]->head;
				if (table[index]->head == table[index]->last)
				{
					free(table[index]);
					table[index] = NULL;
					continue;
				}
				if (!strcmp(table[index]->head->key, key))
				{
					LItem* deleted = table[index]->head;
					table[index]->head = deleted->left;
					deleted->left->right = NULL;
					free(deleted);
					continue;
				}
				if (!strcmp(table[index]->last->key, key))
				{
					LItem* deleted = table[index]->last;
					table[index]->last = deleted->right;
					deleted->right->left = NULL;
					free(deleted);
					continue;
				}
				while (cur->left != NULL)
				{
					if (!strcmp(cur->key, key))
					{
						LItem* deleted = cur;
						cur->left->right = cur->right;
						if (cur->right != NULL)
						{
							cur->right->left = cur->left;
						}
						deleted->left = NULL;
						deleted->right = NULL;
						free(deleted);
						break;
					}
					cur = cur->left;
				}
			}
		}
		else if (select == 3)
		{
			char* key = (char*)malloc(256 * sizeof(char));
			printf("Введите ключ: \n");
			scanf("%s", key);
			int index = Hash(key, size);
			if (Search(table[index], key, index) == 0)
			{
				printf("Элемент не существует\n");
			}
		}
		else if (select == 4)
		{
			for (int i = 0; i < size; i++)
			{
				Show(table[i], i);
			}
		}
		else if (select == 5)
		{
			break;
		}
	}
	system("cls");
}