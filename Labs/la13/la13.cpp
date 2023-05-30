//Программа №13 (РАЗДЕЛ 2, ТЕМА 1) - ПРОСТЕЙШИЕ МЕТОДЫ СОРТИРОВКИ МАССИВОВ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void Create(int *mass, int size)
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
}

void Exchange(int *main, int size)
{
	if (main == NULL)
	{
		return;
	}
	int *mass = (int*)malloc(size * sizeof(int));
	memcpy(mass, main, size * sizeof(int));
	unsigned long count1 = 0, count2 = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			count1++;
			if (mass[j] < mass[j - 1])
			{
				int cur = mass[j - 1];
				mass[j - 1] = mass[j];
				mass[j] = cur;
				count2++;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d ", mass[i]);
	}
	printf("\nСОРТИРОВКА ОБМЕНОМ\nКоличество сравнений: %d\nКоличество перестановок: %d\n", count1, count2);
}

void Insert(int *mass, int size)
{
	if (mass == NULL)
	{
		return;
	}
	unsigned long count1 = 0, count2 = 0;
	int *m = (int*)malloc(size * sizeof(int));
	memcpy(m, mass, size * sizeof(int));
	for (int i = 1; i < size; i++)
	{
		count2++;
		int temp = m[i];
		int j = i - 1;
		count1++;
		while (j >= 0 && temp < m[j])
		{
			count1++;
			count2++;
			m[j + 1] = m[j];
			j--;
		}
		count2++;
		m[j + 1] = temp;
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d ", m[i]);
	}
	printf("\nСОРТИРОВКА ВСТАВКАМИ\nКоличество сравнений: %d\nКоличество перестановок: %d\n", count1, count2 / 3);
}

void Choice(int *mass, int size)
{
	if (mass == NULL)
	{
		return;
	}
	unsigned long count1 = 0, count2 = 0;
	int *m = (int*)malloc(size * sizeof(int));
	memcpy(m, mass, size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		int min = m[i];
		int k = i;
		for (int j = i + 1; j < size; j++)
		{
			count1++;
			if (m[j] < min)
			{
				min = m[j];
				k = j;
			}
		}
		if (k != i)
		{
			m[k] = m[i];
			m[i] = min;
			count2 = count2 + 1;
		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d ", m[i]);
	}
	printf("\nСОРТИРОВКА ВЫБОРОМ\nКоличество сравнений: %d\nКоличество перестановок: %d\n", count1, count2);
}


void main()
{
	setlocale(LC_ALL, "rus");
	int size;
	printf("Размер массива: ");
	scanf("%d", &size);
	int *mass = (int*)malloc(size * sizeof(int));
	Create(mass, size);
	printf("Массив:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", mass[i]);
	}
	int select = 0;
	printf("\n1)Сортировка обменом\n2)Сортировка вставками\n3)Сортировка выбором\n4)Выход\n");
	while (select != 4)
	{
		printf("\nНомер сортировки (1-3) или выход(4): ");
		scanf("%d", &select);
		if (select == 1)
		{
			Exchange(mass, size);
		}
		else if (select == 2)
		{
			Insert(mass, size);
		}
		else if (select == 3)
		{
			Choice(mass, size);
		}
		else if (select == 4)
		{
			break;
		}
	}
}