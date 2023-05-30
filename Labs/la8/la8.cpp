//Программа №8(Раздел 1, Тема 4, Номер 3) - СПИСОК СПИСКОВ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

struct Sub_List
{
	int infsub;
	Sub_List *NextS;
};
struct Main_List
{
	int infmain;
	Main_List *NextM;
	Sub_List *sub;
};

Main_List *list;

void Show(Main_List *list)
{
	Main_List *temp = list;
	printf("Главный список / Связанный список\n");
	if (temp->NextM == NULL)
	{
		printf("Список пуст\n");
	}
	while (temp->NextM != NULL)
	{
		temp = temp->NextM;
		printf("%d              ", temp->infmain);
		Sub_List *subl = temp->sub;
		while (subl != NULL)
		{
			printf(" %d ", subl->infsub);
			subl = subl->NextS;
		}
		printf("\n");
	}
}

void Start(Main_List *list)
{
	system("cls");
	printf("Введите добавляемый элемент:\n");
	int a;
	scanf("%d", &a);
	Main_List *temp = new Main_List;
	temp->infmain = a;
	temp->NextM = NULL;
	temp->sub = NULL;
	list->NextM = temp;
	printf("Элемент добавлен\n");
}
void After(Main_List *list)
{
	if (list->NextM == NULL)
	{
		Start(list);
	}
	else
	{
		int a;
		printf("Введите значение элемента, после которого вы хотите добавить\n");
		scanf("%d", &a);
		Main_List *temp = list->NextM;
		while (temp != NULL)
		{
			if (temp->infmain == a)
			{
				int k;
				printf("Значение нового элемента - ");
				scanf("%d", &k);
				Main_List *pTemp = new Main_List;
				pTemp->infmain = k;
				pTemp->sub = NULL;
				pTemp->NextM = temp->NextM;
				temp->NextM = pTemp;
				printf("Элемент добавлен\n");
			}
			temp = temp->NextM;
		}
	}
}

void Before(Main_List *list)
{
	if (list->NextM == NULL)
	{
		Start(list);
	}
	else {
		int a;
		printf("Введите значение элемента, до которого вы хотите добавить элемент\n");
		scanf("%d", &a);
		Main_List *last = list;
		Main_List *temp = list->NextM;
		while (temp != NULL)
		{
			if (temp->infmain == a)
			{
				int z;
				printf("Значение нового элемента- ");
				scanf("%d", &z);
				Main_List *newtemp = new Main_List;
				newtemp->infmain = z;
				newtemp->sub = NULL;
				newtemp->NextM = temp;
				last->NextM = newtemp;
				printf("Элемент добавлен\n");
				return;
			}
			last = last->NextM;
			temp = temp->NextM;
		}
	}
}

void AddS(Main_List *list)
{
	if (list == NULL)
	{
		printf("Основной список пуст\n");
		return;
	}
	int a;
	printf("Введите элемент главного списка, к которому хотите добавить связанный\n");
	scanf("%d", &a);
	Main_List *temp = list;
	while (temp != NULL)
	{
		if (temp->infmain == a)
		{
			if (temp->sub == NULL)
			{
				int b;
				printf("Введите значение добавляемого элемента:\n");
				scanf("%d", &b);
				Sub_List *subl = new Sub_List;
				subl->infsub = b;
				subl->NextS = NULL;
				temp->sub = subl;
				return;
			}
			int ask;
			int v;
			printf("1) Добавить до заданного\n2) Добавить после заданного\n");
			scanf("%d", &ask);
			Sub_List *subl = temp->sub;
			if (ask == 1)
			{
				printf("Введите элемент, до которого хотите добавить\n");
				scanf("%d", &v);
				printf("Введите добавляемый элемент\n");
				int val;
				scanf("%d", &val);
				if (subl->infsub == v)
				{
					Sub_List *sub2 = new Sub_List;
					sub2->infsub = val;
					sub2->NextS = temp->sub;
					temp->sub = sub2;
					return;
				}
				while (subl->NextS != NULL)
				{
					if (subl->NextS->infsub == v)
					{
						Sub_List * sub2 = new Sub_List;
						sub2->infsub = val;
						sub2->NextS = subl->NextS;
						subl->NextS = sub2;
						return;
					}
					subl = subl->NextS;
				}
			}
			else if (ask == 2)
			{
				printf("Введите элемент, после которого хотите добавить\n");
				scanf("%d", &v);
				printf("Введите добавляемый элемент.(связанный список)\n");
				int val;
				scanf("%d", &val);
				while (subl != NULL)
				{
					if (subl->infsub == v)
					{
						Sub_List *sub2 = new Sub_List;
						sub2->infsub = val;
						sub2->NextS = subl->NextS;
						subl->NextS = sub2;
						return;
					}
					subl = subl->NextS;
				}
			}
		}
		temp = temp->NextM;
	}
}

void Delete(Main_List *list)
{
	if (list == NULL)
	{
		printf("Список пуст.\n");
		return;
	}
	int a;
	printf("Введите значение элемента, которое вы хотите удалить:\n");
	scanf("%d", &a);
	Main_List *temp = list;
	if (temp->infmain == a)
	{
		Main_List *del = list;
		list = list->NextM;
		Sub_List*del2 = temp->sub;
		while (del2 != NULL)
		{
			Sub_List *del1 = del2;
			del2 = del2->NextS;
			free(del1);
		}
		return;
	}
	while (temp->NextM != NULL)
	{
		if (temp->NextM->infmain == a)
		{
			Main_List *del = temp->NextM;
			temp->NextM = del->NextM;
			free(del->sub);
			free(del);
			return;
		}
		temp = temp->NextM;
	}
}

void DeleteS(Main_List *list)
{
	int a;
	int g;
	printf("Введите элемент основного списка, в котором хотите удалить.\n");
	scanf("%d", &g);
	Main_List *temp = list;
	while (temp != NULL)
	{
		if (temp->infmain == g)
		{
			if (temp->sub == NULL)
			{
				printf("Список пуст\n");
				return;
			}
			printf("Введите значение элемента, которое вы хотите удалить:\n");
			scanf("%d", &a);
			Sub_List *subl = temp->sub;
			if (subl->infsub == a)
			{
				Sub_List *del = temp->sub;
				temp->sub = temp->sub->NextS;
				free(del);
				return;
			}
			while (subl->NextS != NULL)
			{
				if (subl->NextS->infsub == a)
				{
					Sub_List *del = subl->NextS;
					subl->NextS = del->NextS;
					free(del);
					return;
				}
				subl = subl->NextS;
			}
		}
		temp = temp->NextM;
	}
}

void Search(Main_List *list)
{
	if (list == NULL)
	{
		printf("Список пуст\n");
		return;
	}
	int a;
	int k = 0;
	printf("Введите значение для поиска:\n");
	scanf("%d", &a);
	Main_List *temp = list;
	while (temp != NULL)
	{
		Sub_List *subl = temp->sub;
		if (temp->infmain == a)
		{
			printf("Найдено в главном списке\n");
			k++;
		}
		if (subl == NULL)
		{
			temp = temp->NextM;
			continue;
		}
		while (subl != NULL)
		{
			if (subl->infsub == a)
			{
				printf("Найдено в связанном списке\n");
				k++;
			}
			subl = subl->NextS;
		}
		temp = temp->NextM;
	}
	if (k == 0)
	{
		printf("Элемент не найден.\n");
	}
}


void main()
{
	setlocale(LC_ALL, "RUS");
	list = new Main_List;
	list->NextM = NULL;
	list->sub = NULL;
	int select = 0;
	while (select != 7)
	{
		printf("1) Добавить элемент в главный список\n2) Добавить элемент в связанный список\n3) Удалить элемент из главного списка\n4) Удалить элемент из связанного списка\n5) Поиск \n6) Вывод структуры\n7) Выход\n");
		scanf("%d", &select);
		system("cls");
		if (select == 1)
		{
			int v;
			printf("1) Добавить до заданного элемента\n2) Добавить после заданного элемента\n");
			scanf("%d", &v);
			if (v == 1)
			{
				Before(list);
			}
			else if (v == 2)
			{
				After(list);
			}
			system("pause");
		}
		else if (select == 2)
		{
			AddS(list);
			system("pause");
		}
		else if (select == 3)
		{
			Delete(list);
			system("pause");
		}
		else if (select == 4)
		{
			DeleteS(list);
			system("pause");
		}
		else if (select == 5)
		{
			Search(list);
			system("pause");
		}
		else if (select == 6)
		{
			Show(list);
			system("pause");
		}
		else if (select == 7)
		{
			break;
		}
		system("cls");
	}
}