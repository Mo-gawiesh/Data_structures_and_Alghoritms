#define _CRT_SECURE_NO_WARNINGS
#include <string>
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

void Shell(int* Mass, int size)
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
	int StepsNum = (int)log2(size);
	int* Steps = (int*)malloc(StepsNum * sizeof(int));
	for (int i = 0; StepsNum >= 1; StepsNum--, i++)
	{
		Steps[i] = pow(2, StepsNum) - 1;
	}

	for (int m = 0; m < (int)log2(size); m++)
	{
		for (int i = Steps[m]; i < size; i++)
		{
			count2++;
			int temp = mass[i];
			int j = i - Steps[m];
			count1++;
			while (j >= 0 && temp < mass[j])
			{
				count2++;
				count1++;
				mass[j + Steps[m]] = mass[j];
				j = j - Steps[m];
			}
			count2++;
			mass[j + Steps[m]] = temp;
		}
	}
	printf("\nМЕТОД ШЕЛЛА\nКоличество сравнений: %d\nКоличество перестановок: %d\n", count1, count2);
	for (int i = 0; i < size; i++) {
		printf("%d  ", mass[i]);
	}
}

void Sito(int* mass, int al, int ar, unsigned long& count1, unsigned long& count2)
{
	int i, j, x;
	i = al;
	j = 2 * al;
	x = mass[al];
	count1 += 2;
	if (j < ar && mass[j + 1] < mass[j]) j++;
	while (j <= ar && mass[j] < x) {
		count1 += 3;
		count2++;
		mass[i] = mass[j];
		i = j;
		j = 2 * j;
		if (j < ar && mass[j + 1] < mass[j]) j++;
	}
	mass[i] = x;
}

void Pyramid(int* Mass, int size)
{
	if (Mass == NULL)
	{
		return;
	}
	printf("Исходный массив:\n");
	for (int i = 0; i < size; i++) {
		printf("%d  ", Mass[i]);
	}

	bool stop = false;
	int temp;
	int left = size / 2 + 1;
	int right = size - 1;
	unsigned long count1 = 0, count2 = 0;
	int* mass = (int*)malloc(size * sizeof(int));
	memcpy(mass, Mass, size * sizeof(int));
	while (left > 0) {
		left--;
		Sito(mass, left, right, count1, count2);
	}
	while (right > 0) {
		count2++;
		temp = mass[0];
		mass[0] = mass[right];
		mass[right] = temp;
		right--;
		Sito(mass, left, right, count1, count2);
	}

	printf("\nПИРАМИДАЛЬНАЯ СОРТИРОВКА\nКоличество сравнений: %d\nКоличество перестановок: %d\n", count1, count2);
	for (int i = 0; i < size; i++) {
		printf("%d  ", mass[i]);
	}
}

void Quick(int* mass, int left, int right, unsigned long& count1, unsigned long& count2)
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
			count1++;
			i++;
		}
		count1++;
		while (mass[j] > medium)
		{
			count1++;
			j--;
		}
		count1++;
		if (i <= j)
		{
			count2++;
			int temp = mass[i];
			mass[i] = mass[j];
			mass[j] = temp;
			i++;
			j--;
		}
		count1++;
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

void QuickMain(int* Mass, int size) {
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
	Quick(mass, 0, size - 1, count1, count2);

	printf("\nБЫСТРАЯ СОРТИРОВКА\nКоличество сравнений: %d\nКоличсетво перестановок: %d\n", count1, count2);
	for (int i = 0; i < size; i++) {
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
		printf("\n1 - Создать новый массив\n2 - Сортировка обменом\n3 - Сортировка вставками\n4 - Сортировка выбором\n5 - Сортировка Шелла\n6 - Пирамидальная сортировка\n7 - Быстрая сортировка\n8 - Выход\n");
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
			Shell(mass, size);
			break;
		case 6:
			Pyramid(mass, size);
			break;
		case 7:
			QuickMain(mass, size);
			break;
		case 8:
			return 0;
		default:
			break;
		}
	}
}