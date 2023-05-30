//программа №1 (раздел 1, тема 2, номер 4) - СТЕК НА ОСНОВЕ ДИНАМИЧЕСКОГО РАСПРЕДЕЛЕНИЯ ПАМЯТИ

#include <iostream>
#include <time.h>

using namespace std;


int failure() {
	int a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nОшибка ввода \n" << endl;
	}
	return a;
}

struct Stack {
	int value;
	Stack *next;
} *sp, *sp_second;

inline void initStack() {
	sp = NULL;
	sp_second = NULL; 
}

bool isEmpty() {
	if (sp == NULL) return 1;
	else return 0;
}

bool isSecondEmpty() {
	if (sp_second == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void show_stack(Stack *_sp) {
	if (_sp != NULL) {
		std::cout << "\n";
		Stack *current;
		current = _sp;
		int i = 1;
		do {
			std::cout << i << ") " << current->value << "\n";
			current = current->next;
			i++;
		} while (current != NULL);
	}
	else {
		std::cout << "Стек пуст.\n";
	}
}

Stack *push(Stack *_sp, int _value) {
	Stack *item = new Stack;
	item->value = _value;
	item->next = _sp;
	_sp = item;
	return _sp;
}

void PushRand() {
	int rcount;
	std::cout << "Сколько чисел добавить? ";
	rcount = failure();
	for (int i = 0; i < rcount; i++)
		sp = push(sp, rand());
}

int pop() {
	if (!isEmpty()) {
		int value = sp->value;
		Stack *current; current = sp;
		sp = sp->next;
		delete current;
		return value;
	}
	else
		return -1;
}

void move_to_second_stek() {
	Stack *current = sp;
	sp = sp->next;
	current->next = sp_second;
	sp_second = current;
}

void add_from_second() {
	Stack *current = sp_second;
	sp_second = sp_second->next;
	current->next = sp;
	sp = current;
}

void menu() {
	int number, value, comd;
	while (true) {
		cout << "___________________________________________________________\n";
		std::cout << "\nВведите номер команды:\n";
		std::cout << "1. Вывести состояние главного стека\n";
		std::cout << "2. Добавить элемент в главный стек\n";
		std::cout << "3. Удалить элемент из главного стека\n";
		std::cout << "4. Добавить несколько рандомных чисел в главный стек\n";
		std::cout << "5. Вывести состояние вспомогательного стека\n";
		std::cout << "0. Завершить работу программы\n";
		std::cout << "Ваш выбор: ";
		number = failure();

		if (number == 1) { 
			std::cout << "Состояние стека: ";
			show_stack(sp);
		}
		else if (number == 2) { 
			std::cout << "Уточните происхождение элемента: \n 1. Создание нового элемента \n 2. С вершины вспомогательного стека\nВаш Выбор: ";
			comd = failure();
			if (comd == 1) {
				std::cout << "Введите целое число: "; value = failure();
				sp = push(sp, value);
			}
			else if (comd == 2) {
				if (!isSecondEmpty()) add_from_second();
				else std::cout << "Вспомогательный стек пуст.\n";
			}
			else
				std::cout << "Ошибка ввода. Повторите ввод команды\n";
		}
		else if (number == 3) { 
			if (!isEmpty()) {
				std::cout << "Уточните команду: \n 1. Действительно удалить элемент с полным освобождением памяти \n 2. Включить его в вершину вспомогательного стека удаленных элементов\nВаш Выбор: ";
				comd = failure();
				if (comd == 1) {
					value = pop();
					if (value != -1) {
						std::cout << "Элемент '" << value << "' удален\n";
					}
					else {
						std::cout << "Стек пуст.\n";
					}
				}
				else if (comd == 2) {
					if (sp != NULL) {
						move_to_second_stek();
					}
					else {
						std::cout << "Стек пуст.\n";
					}
				}
				else {
					std::cout << "Ошибка ввода. Повторите ввод команды\n";
				}
			}
			else {
				std::cout << "Стек пуст. Удалять нечего\n";
			}
		}
		else if (number == 4)  
			PushRand();
		else if (number == 5) { 
			std::cout << "Состояние вспомогательного стека удаленных элементов: ";
			show_stack(sp_second);
		}
		else if (number == 0) {
			break;
		}
		else
			std::cout << "Ошибка ввода. Повторите ввод команды\n";
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	initStack();
	srand(static_cast<unsigned int>(time(0))); 
	menu();
	return 0;
}
