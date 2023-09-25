#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

bool KEY[256];


struct Note {
	char Data;
	Note* Next;
	Note(char data) {
		Data = data;
		Next = nullptr;
	}
};

Note* First;
Note* Last;

void AddNote(char data) {
	Note* PTemp = new Note(data);
	PTemp->Next = nullptr;
	Last->Next = PTemp;
	Last = PTemp;
}
bool IsEmpty() {
	return First == Last;
}
void DeleteNote() {
	if (IsEmpty())
	{
		printf("Очередь пуста!\n");
		return;
	}
	Note* PTemp = First->Next;
	First->Next = PTemp->Next;
	if (First->Next == nullptr) Last = First;
	delete PTemp;
	PTemp = nullptr;
}

void Show() {
	if (IsEmpty()) {
		printf("Очередь пуста!\n");
		return;
	}
	Note* Current = First->Next;
	while (Current != nullptr) {
		printf("%c\n", Current->Data);
		Current = Current->Next;
	}
}

void GetKEY()
{
	int i = 0;
	while (i < 256)
	{
		if (GetAsyncKeyState(i)) KEY[i] = 1; else KEY[i] = 0;
		i++;
	}
}
void Cicle(int a, int b, int c, int d) {
	printf("Цикл запущен\n");
	Sleep(1000);
	srand(time(NULL));
	while (1) {
		int Action = rand() % 100;
		if (Action % 2 == 0)	
		{
			Action = rand() % b + a;
			printf("Выполняется %d добавления\n", Action);
			Sleep(1000);
			for (int i = 0; i < Action; i++) {
				AddNote('A' + rand() % 26);
			}
		}
		else if (Action % 2 == 1) {	
			Action = rand() % d + c;
			printf("Выполняется %d удаления\n", Action);
			Sleep(1000);
			for (int i = 0; i < Action; i++) {
				DeleteNote();
			}
		}
		system("cls");
		Show();
		Sleep(1000);
		GetKEY();
		if (KEY[32]) {
			return;
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int Action, a = 1, b = 3, c = 1, d = 3;
	First = new Note(0);
	First->Next = nullptr;
	Last = First;
	while (1) {
		system("cls");
		printf("Выберите действие:\n1 - Изменить количество добавляемых/удаляемых элементов\n3 - Запустить цикл\n4 - Вывести очередь\n5 - Выйти\n");
		while (!scanf("%d", &Action)) {
			while (getchar() != '\n') {
				printf("Введите заново!\n");
			}
		}
		switch (Action)
		{
		case 1:		//add element
			system("cls");
			printf("[a-b] - диапазон для добавления\na : ");
			scanf("%d", &a);
			fflush(stdin);
			printf("b : ");
			scanf("%d", &b);
			system("cls");
			printf("[c-d] - диапазон для удаления\nc : ");
			fflush(stdin);
			scanf("%d", &c);
			printf("d : ");
			fflush(stdin);
			scanf("%d", &d);
			break;
		case 2:		//delete element
			system("cls");
			DeleteNote();
			system("pause");
			break;
		case 3:		//check full
			system("cls");
			Cicle(a, b, c, d);
			system("pause");
			break;
		case 4:		//show
			system("cls");
			Show();
			system("pause");
			break;
		case 5:		//cancell
			system("cls");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
}