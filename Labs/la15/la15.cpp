//Программа №15 (РАЗДЕЛ 2, ТЕМА 3) - СПЕЦИАЛЬНЫЕ МЕТОДЫ СОРТИРОВКИ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

void Show(int *mass, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", mass[i]);
	}
}

void PocketSortWithMass(int *mass, int size)
{
	int *mass2 = (int*)malloc(size * sizeof(int));
	int p = 0;
	for (int i = 0; i < size; i++)
	{
		mass2[mass[i]] = mass[i];
		p++;
	}
	printf("\nОтсортированный массив:\n");
	Show(mass2, size);
	printf("\n\nКарманная сортировка со вспомогательным массивом\nСравнений: 0\nПерестановок: %d\n", p / 3);
}

void PocketSortWithoutMass(int *mass, int size)
{
	int *m = (int*)malloc(size * sizeof(int));
	memcpy(m, mass, size * sizeof(int));
	unsigned long s = 0, p = 0;
	for (int i = 0; i < size; i++)
	{
		s++;
		while (m[i] != i)
		{
			s++;
			int temp = m[i];
			m[i] = m[temp];
			m[temp] = temp;
			p++;
		}
	}
	printf("\nОтсортированный массив:\n");
	Show(m, size);
	printf("\n\nКарманная сортировка без вспомогательного массива\nСравнений: %d\nПерестановок: %d\n", s, p);
}

struct List
{
	int inf;
	List *next;
	List *left;
};
struct Array {
	List *el;
	List *last;
};

void PocketSort(int *mass, int size)
{
	int *m = (int*)malloc(size * sizeof(int));
	memcpy(m, mass, size * sizeof(int));
	unsigned long p = 0, s = 0;
	Array *result = (Array*)malloc(size*(sizeof(Array)));
	for (int i = 0; i < size; i++)
	{
		result[i].el = NULL;
	}
	for (int i = 0; i < size; i++)
	{
		p++;
		List *next = result[m[i]].el;
		result[m[i]].el = (List*)malloc(sizeof(List));
		result[m[i]].el->next = next;
		result[m[i]].el->inf = m[i];
	}
	for (int i = 0, j = 0; i < size; i++, s++)
	{
		while (result[i].el != NULL)
		{
			s++;
			p++;
			m[j] = result[i].el->inf;
			j++;
			result[i].el = result[i].el->next;
		}
	}
	printf("\nОтсортированный массив:\n");
	Show(m, size);
	printf("\n\nОбобщенная карманная сортировка\nСравнений: %d\nПерестановок: %d\n", s, p / 3);
}

void RadixSort(int *mass, int size)
{
	int *m = (int*)malloc(size * sizeof(int));
	memcpy(m, mass, size * sizeof(int));
	unsigned long p = 0, s = 0;
	Array *result = (Array*)malloc(10 * (sizeof(Array)));
	for (int bitwise = 1; bitwise < 1000; bitwise = bitwise * 10)
	{
		for (int i = 0; i < 10; i++)
		{
			result[i].el = NULL;
			result[i].last = NULL;
		}
		for (int i = 0; i < size; i++)
		{
			p++;
			int index = (m[i] % (10 * bitwise)) / bitwise;
			List *next = result[index].el;
			result[index].el = (List*)malloc(sizeof(List));
			result[index].el->next = next;
			result[index].el->left = NULL;
			result[index].el->inf = m[i];
			if (next != NULL)
			{
				next->left = result[index].el;
			}
			else
			{
				result[index].last = result[index].el;
			}
		}
		for (int i = 0, j = 0; i < 10; i++, s++)
		{
			while (result[i].last != NULL && j < size)
			{
				s++;
				p++;
				m[j] = result[i].last->inf;
				result[i].last = result[i].last->left;
				j++;
			}
		}
	}
	printf("\nОтсортированный массив:\n");
	Show(m, size);
	printf("\n\nПоразрядовая сортировка\nСравнений: %d\nПерестановок: %d\n", s, p / 3);
}

void main()
{
	setlocale(LC_ALL, "RUS");
	int size;
	printf("Размер массива: ");
	scanf("%d", &size);
	int *mass = (int*)malloc(size * sizeof(int));
	int select = 0;
	printf("\n1)Карманная сортировка с вспомогательным массивом\n2)Карманная сортировка\n3)Обобщенная карманная сортировка\n4)Поразрядная сортировка\n5)Выход\n");
	while (select != 5)
	{
		printf("\nНомер сортировки (1-4) или выход(5): ");
		scanf("%d", &select);
		if (select == 1)
		{
			int i = 0;
			int a;
			while (i < size)
			{
				a = rand() % size;
				for (int j = i; j >= 0; j--)
				{
					if (mass[j] == a)
					{
						break;
					}
					else if (j == 0)
					{
						mass[i] = a;
						i++;
					}
				}
			}
			printf("\nИсходный массив:\n");
			Show(mass, size);
			PocketSortWithMass(mass, size);
		}
		else if (select == 2)
		{
			int i = 0;
			int a;
			while (i < size)
			{
				a = rand() % size;
				for (int j = i; j >= 0; j--)
				{
					if (mass[j] == a)
					{
						break;
					}
					else if (j == 0)
					{
						mass[i] = a;
						i++;
					}
				}
			}
			printf("\nИсходный массив:\n");
			Show(mass, size);
			PocketSortWithoutMass(mass, size);
		}
		else if (select == 3)
		{
			printf("\nИсходный массив:\n");
			for (int i = 0; i < size; i++)
			{
				mass[i] = rand() % size;
				printf("%d ", mass[i]);
			}
			PocketSort(mass, size);
		}
		else if (select == 4)
		{
			printf("\nИсходный массив:\n");
			for (int i = 0; i < size; i++)
			{
				mass[i] = rand() % 900 + 100;
				printf("%d ", mass[i]);
			}
			RadixSort(mass, size);
		}
		else if (select == 5)
		{
			break;
		}
	}
}