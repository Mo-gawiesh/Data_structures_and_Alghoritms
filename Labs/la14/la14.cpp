//Программа №14 (РАЗДЕЛ 2, ТЕМА 2) - ПРОСТЕЙШИЕ МЕТОДЫ СОРТИРОВКИ МАССИВОВ + ТРИ УЛУЧШЕННЫХ МЕТОДА СОРТИРОВКИ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void Exchange(int *m, int size)
{
	if (m == NULL)
	{
		return;
	}
	int *mass = (int*)malloc(size * sizeof(int));
	memcpy(mass, m, size * sizeof(int));
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
	printf("\nСортеировка обменом\nКоличество сравнений: %d\nКоличество перестановок: %d\n", count1, count2);
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
	printf("\nСортировка вставками\nКоличество сравнений: %d\nКоличество перестановок: %d\n", count1, count2 / 3);
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
		count2++;
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
			count2 = count2 + 2;
		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d ", m[i]);
	}
	printf("\nСортировка выбором\nКоличество сравнений: %d\nКоличество перестановок: %d\n", count1, count2);
}

void Shell(int *m, int size)
{
	if (m == NULL)
	{
		return;
	}
	unsigned long count1 = 0, count2 = 0;
	int *mass = (int*)malloc(size * sizeof(int));
	memcpy(mass, m, size * sizeof(int));
	int k = (int)log2(size);
	int *steps = (int*)malloc(k * sizeof(int));
	for (int i = 0; k >= 1; k--, i++)
	{
		steps[i] = pow(2, k) - 1;
	}
	for (int m = 0; m < (int)log2(size); m++)
	{
		for (int i = steps[m]; i < size; i++)
		{
			count2++;
			int temp = mass[i], j = i - steps[m];
			count1++;
			while (j >= 0 && temp < mass[j])
			{
				count2++;
				count1++;
				mass[j + steps[m]] = mass[j];
				j = j - steps[m];
			}
			count2++;
			mass[j + steps[m]] = temp;
		}
	}
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", mass[i]);
	}
	printf("\nМетод Шелла\nКоличество сравнений: %d\nКоличество перестановок: %d\n", count1, count2 / 3);
}

void step2(int *mass, int size, unsigned long &count2, unsigned long &count1)
{
	int k = size - 1;
	int temp, num = 0, i = 0, step = 0;
	bool stop = false;
	while (k > 0)
	{
		count2++;
		temp = mass[0];
		mass[0] = mass[k];
		mass[k] = temp;
		k--;
		while ((2 * i + 1 <= k) && (stop == false))
		{
			if (2 * i + 2 <= k)
			{
				if (mass[2 * i + 1] < mass[2 * i + 2])
				{
					count1++;
					num = 2 * i + 2;
				}
				else
				{
					count1++;
					num = 2 * i + 1;
				}
			}
			else
			{
				num = 2 * i + 1;
			}
			if (mass[i] <= mass[num])
			{
				count1++;
				count2++;
				temp = mass[num];
				mass[num] = mass[i];
				mass[i] = temp;
				i = num;
			}
			else
			{
				count1;
				stop = true;
			}
		}
		stop = false;
		i = 0;
	}
}

void Pyramid(int *m, int size)
{
	bool stop = false;
	int i = size / 2 - 1;
	unsigned long count1 = 0, count2 = 0;
	int *mass = (int*)malloc(size * sizeof(int));
	memcpy(mass, m, size * sizeof(int));
	int max, temp, num, p1, p2, co = 0;
	while (i >= 0)
	{
		if ((2 * i + 1 <= size - 1) && (2 * i + 2 <= size - 1))
		{
			p1 = mass[2 * i + 1];
			p2 = mass[2 * i + 2];
		}
		else
		{
			if (2 * i + 1 <= size - 1)
			{
				p1 = mass[2 * i + 1];
				p2 = p1 - 1;
			}
		}
		if (p1 > p2)
		{
			count1++;
			max = p1;
			num = 2 * i + 1;
		}
		else
		{
			count1++;
			max = p2;
			num = 2 * i + 2;
		}
		if (mass[i] < max)
		{
			count1++;
			if (num > size / 2 - 1)
			{
				count2++;
				temp = mass[i];
				mass[i] = mass[num];
				mass[num] = temp;
			}
			else
			{
				count2++;
				temp = mass[i];
				mass[i] = mass[num];
				mass[num] = temp;
				int j = num;
				while ((2 * j + 1 <= size - 1) && (stop != true))
				{
					p1 = mass[2 * j + 1];
					if (2 * j + 2 <= size - 1)
					{
						p2 = mass[2 * j + 2];
					}
					if (p1 > p2)
					{
						count1++;
						max = p1;
						num = 2 * j + 1;
					}
					else
					{
						max = p2;
						num = 2 * j + 2;
					}
					if (mass[j] < max)
					{
						count2++;
						count1++;
						temp = mass[j];
						mass[j] = mass[num];
						mass[num] = temp;
						j = num;
					}
					else
					{
						stop = true;
					}
				}
				stop = false;
			}
		}
		else
		{
			count1++;
		}
		i--;
	}
	step2(mass, size, count2, count1);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", mass[i]);
	}
	printf("\nПирамидальная сортировка\nКоличество сравнений: %d\nКоличество перестановок: %d\n", count1, count2);
}

void Quick(int *mass, int left, int right, unsigned long &count1, unsigned long &count2)
{
	if (mass == NULL)
	{
		return;
	}
	int i = left, j = right;
	int medium = mass[(i + j) / 2];
	do
	{
		count1++;
		while (mass[i] < medium)
		{
			i++;
			count1++;
		}
		count1++;
		while (mass[j] > medium)
		{
			count1++;
			j--;
		}
		if (i <= j)
		{
			count2++;
			int temp = mass[i];
			mass[i] = mass[j];
			mass[j] = temp;
			i++;
			j--;
		}
	} while (i < j);
	if (left < j)
	{
		Quick(mass, left, j, count1, count2);
	}
	if (right > i)
	{
		Quick(mass, i, right, count1, count2);
	}
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
	printf("\n1)Сортировка обменом\n2)Сортировка вставками\n3)Сортировка выбором\n4)Быстрая сортировка\n5)Метод Шелла\n6)Пирамидальная сортировка\n7)Выход\n");
	while (select != 7)
	{
		printf("\nНомер сортировки (1-6) или выход(7): ");
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
			unsigned long count1 = 0, count2 = 0;
			int *m = (int*)malloc(size * sizeof(int));
			memcpy(m, mass, size * sizeof(int));
			Quick(m, 0, size - 1, count1, count2);
			for (int i = 0; i < size; i++)
			{
				printf("%d ", m[i]);
			}
			printf("\nБЫСТРАЯ СОРТИРОВКА\nКоличество сравнений: %d\nКоличсетво перестановок: %d\n", count1, count2);
		}
		else if (select == 5)
		{
			Shell(mass, size);
		}
		else if (select == 6)
		{
			Pyramid(mass, size);
		}
	}
}