//программа №2 (раздел 1, тема 2, номер 5) - КОЛЬЦЕВАЯ ОЧЕРЕДЬ НА ОСНОВЕ МАССИВА (СТАТИЧЕСКАЯ РЕАЛИЗАЦИЯ)

#include <iostream>

using namespace std;

const int ARRAY_SIZE = 5;

struct Queue {
	int First, Last; 
	int ARRAY_QUEUE[ARRAY_SIZE]; 
	int count;

	void initQueue() { 
		First = Last = 0;
	}

	int isempty() { 
		if (count == 0) { 
			return 1;
		}
		else {
			return 0;
		}
	}

	int isfull() { 
		if (count >= ARRAY_SIZE) {
			return 1;
		}
		else {
			return 0;
		}
	}

	void push(int value) { 

		if (!isfull()) { 
			ARRAY_QUEUE[Last] = value;
			Last++;
			if (Last == ARRAY_SIZE) Last = 0; 
			count++;
		}
		else {
			std::cout << "\nДобавление невозможно. Очередь переполнена.\n";
		}

	}

	int pop() { 

		if (!isempty()) { 
			int value = ARRAY_QUEUE[First];
			First++;
			if (First == ARRAY_SIZE) First = 0; 
			count--;
			return value;
		}
		else {
			std::cout << "\nУдалять нечего. Очередь пуста.\n";
			return -1;
		}
	}

	void show_queue() {
		if (!isempty()) {
			std::cout << "\n";
			int current = First;
			int  i = 1;
			do {
				std::cout << i << ") " << ARRAY_QUEUE[current] << "\n";
				current++;
				if (current == ARRAY_SIZE) current = 0; 
				i++;
			} while (current != Last);
		}
		else {
			std::cout << "Очередь пуста\n";
		}
	}

} ring; 

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

void menu() {
	int number, value;
	setlocale(LC_ALL, "Russian");
	while (true) {
		cout << "___________________________________________________________\n";
		std::cout << "\nВведите номер команды:\n";
		std::cout << "1. Проверка пустоты очереди\n";
		std::cout << "2. Проверка заполненности очереди\n";
		std::cout << "3. Добавить элемент в конец очереди\n";
		std::cout << "4. Удалить элемент из начала очереди\n";
		std::cout << "5. Вывод текущего состояния очереди на экран\n";
		std::cout << "0. Завершить работу программы\n";
		std::cout << "Введите номер команды: ";
		number = failure();

		if (number == 1) { 
			if (ring.isempty() == 1) {
				std::cout << "\nПроверка очереди на пустоту... очередь пустая\n";
			}
			else {
				std::cout << "\nПроверка очереди на пустоту... очередь не пустая\n";
			}
		}
		else if (number == 2) { 
			if (ring.isfull() == 1) {
				std::cout << "\nПроверка очереди на заполненность... очередь полная\n";
			}
			else {
				std::cout << "\nПроверка очереди на заполненность... очередь не полная\n";
			}
		}
		else if (number == 3) { 

			if (ring.isfull() == 0) {
				std::cout << "\nВведите целое положительное число: ";
				value = failure();
				ring.push(value);
			}
			else {
				std::cout << "\nДобавление невозможно. очередь переполнена.\n";
			}

		}
		else if (number == 4) { 

			value = ring.pop();
			if (value != -1) {
				std::cout << "\nЭлемент '" << value << "' удален из очереди\n";
			}

		}
		else if (number == 5) { 
			std::cout << "\nСостояние очереди: ";
			ring.show_queue();
		}

		else if (number == 0) 
			break;
		else {
			std::cout << "\nОшибка ввода. Повторите ввод команды\n";
		}

	}
}

int main() {
	ring.initQueue(); 
	menu(); 
	return 0;
}
