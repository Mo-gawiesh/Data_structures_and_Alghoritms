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
		printf("������� �����!");
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
		printf("������� �����!");
		system("pause");
		return;
	}
	int Value;
	printf("������� ����������: ");
	while (!scanf("%d", &Value)) {
		while (getchar() != '\n') {
			printf("������� ������!\n");
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
		printf("������� �����!\n");
		return;
	}
	printf("%d\n", *note->First);
	note->First++;
	note->Counter--;
	if (note->First == &note->Data[MassSize]) note->First = &note->Data[0];
}

void Show(Note* note) {
	if (note->Counter == 0) {
		printf("������� �����!\n");
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
		printf("�������� ��������:\n1 - �������� �������\n2 - ������� �������\n3 - �������� �������/������������� �������\n4 - ������� �������\n5 - �����\n");
		while (!scanf("%d", &Action)) {
			while (getchar() != '\n') {
				printf("������� ������!\n");
			}
		}
		switch (Action)
		{
		case 1:		//add element
			system("cls");
			printf("1 - ���� �������\n2 - ��������� ���������\n3 - �����\n");
			while (!scanf("%d", &Action)) {
				while (getchar() != '\n') {
					printf("������� ������!\n");
				}
			}
			switch (Action) {
			case 1:
				printf("������� �����: ");
				while (!scanf("%d", &Action)) {
					while (getchar() != '\n') {
						printf("������� ������!\n");
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
				printf("������� �����\n");
			}
			else if (MyMassive->Counter != 0 && MyMassive->Counter != 32) {
				printf("������� ��������. ���� - %d\n", MassSize-MyMassive->Counter);
			}
			else if (MyMassive->Counter == 0) {
				printf("������� �����\n");
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



