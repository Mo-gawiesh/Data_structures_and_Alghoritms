#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>


struct SubLNode
{
	int Data;
	SubLNode* Next;
};


struct MainLNode
{
	int Data;
	MainLNode* Next;
	SubLNode* SubList;
};


void SetFirst(MainLNode* List) {
	if (List->Next == nullptr) {
		printf("Введите первый элемент списка: ");
		int data;
		scanf("%d", &data);
		MainLNode* PTemp = new MainLNode();
		PTemp->Data = data;
		List->Next = PTemp;
	}
	else {
		printf("Первый элемент уже задан.\n");
	}
}

void MainAddAfter(MainLNode* List) {
	if (List->Next == nullptr) {
		SetFirst(List);
		return;
	}
	MainLNode* Current = List->Next;
	int AData;
	printf("Введите элемент, после которого нужно добавить: ");
	scanf("%d", &AData);
	while (Current != nullptr) {
		if (Current->Data == AData) {
			int data;
			printf("Введите информационную часть нового элемента: ");
			scanf("%d", &data);
			MainLNode* PTemp = new MainLNode();
			PTemp->Data = data;
			PTemp->Next = Current->Next;
			Current->Next = PTemp;
			printf("Добавление произведено успешно.\n");
			return;
		}
		Current = Current->Next;
	}
}
void MainAddBefore(MainLNode* List) {
	if (List->Next == nullptr) {
		SetFirst(List);
		return;
	}
	MainLNode* Current = List->Next;
	MainLNode* Prev = List;
	int AData;
	printf("Введите элемент, до которого нужно добавить: ");
	scanf("%d", &AData);
	while (Current != nullptr) {
		if (Current->Data == AData) break;
		Current = Current->Next;
		Prev = Prev->Next;
	}
	int data;
	printf("Введите информационную часть нового элемента: ");
	scanf("%d", &data);
	MainLNode* PTemp = new MainLNode();
	PTemp->Data = data;
	PTemp->Next = Current;
	Prev->Next = PTemp;
	printf("Добавление произведено успешно.\n");
}

void Show(MainLNode* List) {
	system("cls");
	MainLNode* Current = List->Next;
	while (Current != nullptr) {
		printf("%d : ", Current->Data);
		if (Current->SubList != nullptr) {
			SubLNode* SCurrent = Current->SubList;
			while (SCurrent != nullptr)
			{
				printf("%d  ", SCurrent->Data);
				SCurrent = SCurrent->Next;
			}
			printf("\n");
		}
		Current = Current->Next;
		printf("\n");
	}
}
void AddSub(MainLNode* List) {
	if (List->Next == nullptr) {
		printf("Главный список пуст.");
		return;
	}
	int MData;
	printf("Введите элемент главного списка, в который нужно добавить элемент: ");
	scanf("%d", &MData);
	MainLNode* Current = List->Next;
	while (Current != nullptr)
	{
		if (Current->Data == MData) {
			if (Current->SubList == nullptr) {
				SubLNode* SPTemp = new SubLNode();
				int sdata;
				printf("Введите первый элемент вспомогательного списка: ");
				scanf("%d", &sdata);
				SPTemp->Data = sdata;
				Current->SubList = SPTemp;
				printf("Элемент успешно добавлен.\n");
				return;
			}
			int Act;
			printf("1 - Добавить после\n2 - Добавить до\n");
			scanf("%d", &Act);
			SubLNode* SCurrent = Current->SubList;
			switch (Act)
			{
			case 1:
				printf("Введите элемент вспомогательного списка, после которого нужно добавить: ");
				scanf("%d", &Act);
				while (SCurrent != nullptr) {
					if (SCurrent->Data == Act) {
						SubLNode* SPTemp = new SubLNode();
						printf("Введите новый элемент: ");
						scanf("%d", &SPTemp->Data);
						SPTemp->Next = SCurrent->Next;
						SCurrent->Next = SPTemp;
						printf("Элемент успешно добавлен.\n");
						return;
					}
					SCurrent = SCurrent->Next;
				}
				printf("Элемент не найден.\n");
				break;
			case 2:
				printf("Введите элемент вспомогательного списка, до которого нужно добавить: ");
				scanf("%d", &Act);
				if (SCurrent->Data == Act) {
					SubLNode* SPTemp = new SubLNode();
					printf("Введите новый элемент:");
					scanf("%d", &SPTemp->Data);
					SPTemp->Next = SCurrent;
					Current->SubList = SPTemp;
					printf("Элемент успешно добавлен.\n");
					return;
				}
				SubLNode* Prev = SCurrent;
				SCurrent = SCurrent->Next;
				while (SCurrent != nullptr) {
					if (SCurrent->Data == Act) {
						SubLNode* SPTemp = new SubLNode();
						printf("Введите новый элемент: ");
						scanf("%d", &SPTemp->Data);
						SPTemp->Next = SCurrent;
						Prev->Next = SPTemp;
						printf("Элемент успешно добавлен.\n");
						return;
					}
					Prev = Prev->Next;
					SCurrent = SCurrent->Next;
				}
				printf("Элемент не найден.\n");
				break;
			}

		}
		Current = Current->Next;
	}

}

void Delete(MainLNode* List) {
	if (List->Next == nullptr) {
		printf("Список пуст.\n");
		return;
	}
	int MData;
	printf("Введите элемент главного списка для удаления: ");
	scanf("%d", &MData);
	MainLNode* Current = List->Next;
	MainLNode* Previous = List;
	while (Current != nullptr) {
		if (Current->Data == MData) {
			Previous->Next = Current->Next;
			printf("Удален элемент %d", Current->Data);
			SubLNode* SubCur = Current->SubList;
			while (SubCur != nullptr) {
				Current->SubList = Current->SubList->Next;
				delete SubCur;
				SubCur = nullptr;
				SubCur = Current->SubList;
			}

			delete Current;
			Current = nullptr;
			return;
		}
		Current = Current->Next;
		Previous = Previous->Next;
	}
	printf("В главном списке нет такого элемента.\n");
}

void DeleteSub(MainLNode* List) {
	if (List->Next == nullptr) {
		printf("Список пуст.\n");
		return;
	}
	int MData;
	printf("Введите элемент главного списка: ");
	scanf("%d", &MData);
	MainLNode* Current = List->Next;
	MainLNode* Prev = List;
	while (Current != nullptr) {
		if (Current->Data == MData) {
			if (Current->SubList == nullptr) {
				printf("Вспомогательный список пуст.\n");
				return;
			}
			int SData;
			printf("Введите элемент для удаления:");
			scanf("%d", &SData);
			SubLNode* SCurrent = Current->SubList;
			if (SCurrent->Data == SData) {
				SubLNode* temp = Current->SubList;
				Current->SubList = Current->SubList->Next;
				delete temp;
				temp = nullptr;
				printf("Элемент удален.\n");
				return;
			}
			SCurrent = SCurrent->Next;
			SubLNode* SPrev = Current->SubList;
			while (SCurrent != nullptr) {
				if (SCurrent->Data == SData) {
					SPrev->Next = SCurrent->Next;
					printf("Элемент удален.\n");
					delete SCurrent;
					SCurrent = nullptr;
					return;
				}
				SPrev = SPrev->Next;
				SCurrent = SCurrent->Next;
			}
			printf("В списке нет такого элемента.\n");
			return;
		}
		Current = Current->Next;
	}
	printf("В главном списке нет такого элемента.\n");
}

int main()
{
	setlocale(LC_ALL, "rus");
	MainLNode* MainList = new MainLNode();
	MainList->Next = nullptr;
	int Act;
	while (1) {
		system("cls");
		printf("Выберите действие:\n1 - Добавить элемент в главный список\n2 - Добавить элемент в вспомогательный список\n3 - Вывод\n4 - Удалить элемент из главного списка\n5 - Удалить элемент из вспомогательного списка\n6 - Выход\n");
		scanf("%d", &Act);
		switch (Act)
		{
		case 1:
			if (MainList->Next == nullptr) {
				SetFirst(MainList);
				break;
			}
			Act;
			printf("1 - Добавить после\n2 - Добавить до\n");
			scanf("%d", &Act);
			switch (Act)
			{
			case 1:
				MainAddAfter(MainList);
				break;
			default:
				MainAddBefore(MainList);
				break;
			}
			system("pause");
			break;
		case 2:
			AddSub(MainList);
			system("pause");
			break;
		case 3:
			Show(MainList);
			system("pause");
			break;
		case 4:
			Delete(MainList);
			system("pause");
			break;
		case 5:
			DeleteSub(MainList);
			system("pause");
			break;
		case 6:
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}