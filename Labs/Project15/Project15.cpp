#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

void Show(int* mass, int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
}

void PocketSortWithMass(int* mass, int size)
{
	int* mass2 = (int*)malloc(size * sizeof(int));
	int p = 0;
	for (int i = 0; i < size; i++)
	{
		mass2[mass[i]] = mass[i];
		p++;
	}
	cout << "\nОтсортированный массив:" << endl;
	Show(mass2, size);
	cout << "КАРМАННАЯ СОРТИРОВКА С ВСПОМОГАТЕЛЬНЫМ МАССИВОМ\nСравнений: 0\nПерестановок: " << p / 3 << endl;
}

void PocketSortWithoutMass(int* mass, int size)
{
	int* m = (int*)malloc(size * sizeof(int));
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
	cout << "\nОтсортированный массив:" << endl;
	Show(m, size);
	cout << "КАРМАННАЯ СОРТИРОВКА БЕЗ ВСПОМОГАТЕЛЬНОГО МАССИВА\nСравнений: " << s << "\nПерестановок: " << p << endl;
}

struct List
{
	int inf;
	List* next;
	List* prev;
};
struct Array {
	List* el;
	List* last;
};

void PocketSort(int* mass, int size)
{
	int* m = (int*)malloc(size * sizeof(int));
	memcpy(m, mass, size * sizeof(int));
	unsigned long p = 0, s = 0;
	Array* RMass = (Array*)malloc(size * (sizeof(Array)));
	for (int i = 0; i < size; i++)
	{
		RMass[i].el = NULL;
	}
	for (int i = 0; i < size; i++)
	{
		p++;
		List* next = RMass[m[i]].el;
		RMass[m[i]].el = (List*)malloc(sizeof(List));
		RMass[m[i]].el->next = next;
		RMass[m[i]].el->inf = m[i];
	}
	for (int i = 0, j = 0; i < size; i++, s++)
	{
		while (RMass[i].el != NULL)
		{
			s++;
			p++;
			m[j] = RMass[i].el->inf;
			j++;
			RMass[i].el = RMass[i].el->next;
		}
	}
	cout << "Отсортированный массив:" << endl;
	Show(m, size);
	cout << "ОБОБЩЕННАЯ КАРМАННАЯ СОРТИРОВКА\nСравнений: " << s << "\nПерестановок: " << p / 3 << endl;
}

void RadixSort(int* mass, int size)
{
	int* m = (int*)malloc(size * sizeof(int));
	memcpy(m, mass, size * sizeof(int));
	unsigned long p = 0, s = 0;
	Array* result = (Array*)malloc(10 * (sizeof(Array)));
	for (int bitwise = 1; bitwise < size; bitwise = bitwise * 10)
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
			List* next = result[index].el;
			result[index].el = (List*)malloc(sizeof(List));
			result[index].el->next = next;
			result[index].el->prev = NULL;
			result[index].el->inf = m[i];
			if (next != NULL)
			{
				next->prev = result[index].el;
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
				result[i].last = result[i].last->prev;
				j++;
			}
		}
	}
	cout << "Отсортированный массив:" << endl;
	Show(m, size);
	cout << "ПОРАЗРЯДНАЯ СОРТИРОВКА\nСравнений: " << s << "\nПерестановок: " << p / 3 << endl;
}

void main()
{
	setlocale(LC_ALL, "RUS");
	int size;
	cout << "Размер массива: ";
	scanf("%d", &size);
	int* mass = (int*)malloc(size * sizeof(int));
	int select = 0;
	while (select != 5)
	{
		cout << "1 - Карманная сортировка с вспомогательным массивом\n2 - Карманная сортировка\n3 - Обобщенная карманная сортировка\n4 - Поразрядная сортировка\n5 - Выход\n" << endl;
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
			cout << "Исходный массив:" << endl;
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
			cout << "Исходный массив:" << endl;
			Show(mass, size);
			PocketSortWithoutMass(mass, size);
		}
		else if (select == 3)
		{
			for (int i = 0; i < size; i++) {
				mass[i] = rand() & (size-1);
			}
			cout << "Исходный массив:" << endl;
			Show(mass, size);
			PocketSort(mass, size);
		}
		else if (select == 4)
		{
			for (int i = 0; i < size; i++) {
				mass[i] = rand() & (size - 1);
			}
			cout << "Исходный массив:" << endl;
			Show(mass, size);
			RadixSort(mass, size);
		}
		else if (select == 5)
		{
			break;
		}
	}
}