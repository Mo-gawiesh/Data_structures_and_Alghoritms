#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
constexpr auto MassSize = 4;

struct Note {
	int Data[MassSize];
	int* First;
	int* Last;
	int Counter;
};

void AddNote(Note* note, int data) {
	if (note->Counter == MassSize){
		printf("Очередь полна!");
		system("pause");
		return;
	}	
	*note->Last = data;
	note->Last++;
	if (note->Last == &note->Data[MassSize]) note->Last = &note->Data[0];
	++note->Counter;
}


void AddManyNotes(Note* note) {
	if (note->Counter == MassSize) {
		printf("Очередь пуста!");
		system("pause");
		return;
	}
	int Value;
	printf("Введите количество: ");
	while (!scanf("%d", &Value)) {
		while (getchar() != '\n') {
			printf("Введите заново!\n");
		}
	}
	while (Value != 0) {	
		*note->Last = rand();
		++note->Last;
		--Value;
		if (note->Last == &note->Data[MassSize]) note->Last = &note->Data[0];
		++note->Counter;
		if (note->Last == note->First) return;
	}	
}

void DeleteNote(Note* note) {
	if (note->Counter == 0)
	{
		printf("Очередь пуста!\n");
		return;
	}
	printf("%d\n", *note->First);
	note->First++;
	note->Counter--;
	if (note->First == &note->Data[MassSize]) note->First = &note->Data[0];
}

void Show(Note* note) {
	if (note->Counter == 0) {
		printf("Очередь пуста!\n");
		return;
	}
	int* Current = note->First;
	for(int i = 0; i != note->Counter; i++)
	{
		if (Current == &note->Data[MassSize]) Current = &note->Data[0];
		printf("%d : %d\n", i+1, *Current);
		Current++;
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int Action;
	Note *MyMassive = (Note*)malloc(sizeof(Note));
	MyMassive->First = &MyMassive->Data[0];
	MyMassive->Last = &MyMassive->Data[0];
	MyMassive->Counter = 0;
	while (1) {
		system("cls");
		printf("Выберите действие:\n1 - Добавить элемент\n2 - Удалить элемент\n3 - Проверка пустоты/заполненности очереди\n4 - Вывести очередь\n5 - Выйти\n");
		while (!scanf("%d", &Action)) {
			while (getchar() != '\n') {
				printf("Введите заново!\n");
			}
		}
		switch (Action)
		{
		case 1:		//add element
			system("cls");
			printf("1 - Один элемент\n2 - Несколько элементов\n3 - Назад\n");
			while (!scanf("%d", &Action)) {
				while (getchar() != '\n') {
					printf("Введите заново!\n");
				}
			}
			switch (Action) {
			case 1:
				printf("Введите число: ");
				while (!scanf("%d", &Action)) {
					while (getchar() != '\n') {
						printf("Введите заново!\n");
					}
				}
				AddNote(MyMassive, Action);
				break;
			case 2:
				AddManyNotes(MyMassive);
				break;
			case 3:
				break;
				break;
			}
			break;
		case 2:		//delete element
			system("cls");
			DeleteNote(MyMassive);
			system("pause");
			break;
		case 3:		//check full
			system("cls");
			if (MyMassive->Counter == 32) {
				printf("Очередь полна\n");
			}
			else if (MyMassive->Counter != 0 && MyMassive->Counter != 32) {
				printf("Очередь неполная. Мест - %d\n", MassSize-MyMassive->Counter);
			}
			else if (MyMassive->Counter == 0) {
				printf("Очередь пуста\n");
			}
			system("pause");
			break;
		case 4:		//show
			system("cls");
			Show(MyMassive);
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



