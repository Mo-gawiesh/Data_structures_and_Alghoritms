#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int* Create(int size)
{
	int* Mass = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		Mass[i] = rand() % 100 + 1;
	}
	return Mass;
}

void Exchange(int* Mass, int size)
{
	if (Mass == NULL)
	{
		return;
	}
	printf("Исходный массив:\n");
	for (int i = 0; i < size; i++) {
		printf("%d  ", Mass[i]);
	}

	int* mass = (int*)malloc(size * sizeof(int));
	memcpy(mass, Mass, size * sizeof(int));
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
	printf("\nСОРТИРОВКА ОБМЕНОМ\nКоличество сравнений: %d\nКоличество перестановок: %d\n", count1, count2);
	for (int i = 0; i < size; i++)
	{
		printf("%d  ", mass[i]);
	}
}


void Insert(int* Mass, int size)
{
	if (Mass == NULL)
	{
		return;
	}
	printf("Исходный массив:\n");
	for (int i = 0; i < size; i++) {
		printf("%d  ", Mass[i]);
	}
	unsigned long count1 = 0, count2 = 0;
	int* mass = (int*)malloc(size * sizeof(int));
	memcpy(mass, Mass, size * sizeof(int));
	for (int i = 1; i < size; i++)
	{
		count2++;
		int temp = mass[i];
		int j = i - 1;
		count1++;
		while (j >= 0 && temp < mass[j])
		{
			count1++;
			count2++;
			mass[j + 1] = mass[j];
			j--;
		}
		count2++;
		mass[j + 1] = temp;
	}
	printf("\nСОРТИРОВКА ВСТАВКАМИ\nКоличество сравнений: %d\nКоличество перестановок: %d\n", count1, count2);
	for (int i = 0; i < size; i++)
	{
		printf("%d  ", mass[i]);
	}
}

void Choice(int* Mass, int size)
{
	if (Mass == NULL)
	{
		return;
	}
	printf("Исходный массив:\n");
	for (int i = 0; i < size; i++) {
		printf("%d  ", Mass[i]);
	}
	unsigned long count1 = 0, count2 = 0;

	int* mass = (int*)malloc(size * sizeof(int));
	memcpy(mass, Mass, size * sizeof(int));

	for (int i = 0; i < size; i++)
	{
		int min = mass[i];
		int k = i;
		for (int j = i + 1; j < size; j++)
		{
			count1++;
			if (mass[j] < min)
			{
				min = mass[j];
				k = j;
			}
		}
		if (k != i)
		{
			mass[k] = mass[i];
			mass[i] = min;
			count2++;
		}
	}
	printf("\nСОРТИРОВКА ВЫБОРОМ\nКоличество сравнений: %d\nКоличество перестановок: %d\n", count1, count2);
	for (int i = 0; i < size; i++)
	{
		printf("%d  ", mass[i]);
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	int size;
	printf("Введите размер массива: ");
	scanf("%d", &size);
	int* mass = Create(size);
	int select = 0;
	while (1)
	{
		printf("\n1 - Создать новый массив\n2 - Сортировка обменом\n3 - Сортировка вставками\n4 - Сортировка выбором\n5 - Выход\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("Введите размер массива: ");
			scanf("%d", &size);
			free(mass);
			mass = Create(size);
			break;
		case 2:
			Exchange(mass, size);
			break;
		case 3:
			Insert(mass, size);
			break;
		case 4:
			Choice(mass, size);
			break;
		case 5:
			return 0;
		default:
			break;
		}
	}
}