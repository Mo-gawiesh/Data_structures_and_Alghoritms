//программа №3 (Раздел 1, Тема 2, Номер 7) - КОЛЬЦЕВАЯ ОЧЕРЕДЬ НА ОСНОВЕ МАССИВА СО СЛУЧАЙНЫМ ЧИСЛОМ ДОБАВЛЯЕМЫХ И УДАЛЯЕМЫХ ЭЛЕМЕНТОВ (СТАТИЧЕСКАЯ РЕАЛИЗАЦИЯ)

#include <windows.h> 
#include <iostream>
#include <random>
#include <string>
#include <chrono>
#include <stdlib.h>
#include <iomanip>
#include <thread>

using namespace std;
char symbols[] = "abcdefghijklmnopqrstuvwxyz";

int secondsTime = 5;
int maxElementToAction = 3;

struct Queue
{
	char value;
	Queue* next;

	Queue(char value)
	{
		this->value = value;
		this->next = NULL;
	}
};

Queue* first;
Queue* last;

bool isEmpty()
{
	return first == NULL;
}

void push(char value)
{
	Queue* queue = new Queue(value);
	if (isEmpty())
	{
		first = queue;
	}
	else
		last->next = queue;
		last = queue;
}

char get()
{
	if (!isEmpty())
	{
		char value = first->value;
		Queue* temp = first;
		first = first->next;
		delete temp;
		return value;
	}
}

string getAllString()
{
	string output = "";
	Queue* temp = first;
	while (temp != NULL)
	{
		output += temp->value;
		temp = temp->next;
	}
	return output;
}

void printInfo(string info)
{
	cout << ""<< info << "\n";
}

int getRandom(int maxValue)
{
	return (rand() % maxValue) + 1;
}

char getRandomChar()
{
	return symbols[getRandom(26)];
}

void randomAction()
{
	int randomAction = getRandom(100);
	int randomCount = getRandom(maxElementToAction);
	bool isPush = randomAction % 2 == 0;
	printInfo(("Действие: " + string((isPush ? "добавление" : "удаление"))) + string("\nКоличество элементов: ") + to_string(randomCount));
	if (isPush)
	{
		for (int i = 0; i < randomCount; i++)
		{
			char symbol = getRandomChar();
			push(symbol);
			printInfo("Добавлено: [" + string(1, symbol) + string("]"));
		}
	}
	else
	{
		for (int i = 0; i < randomCount; i++)
		{
			if (!isEmpty())
			{
				printInfo("Удалено: [" + string(1, get()) + string("]"));
			}
			else
			{
				printInfo("Очередь пустая");
				break;
			}
		}
	}
	printInfo(getAllString());
}

int hours = 0;
int minutes = 0;
double seconds = 0;

void timer()
{
	srand(time(NULL));
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		seconds += 0.1;
		if (seconds >= secondsTime)
		{
			printInfo("");
			randomAction();
			seconds = 0;
		}
		if (GetKeyState('Q') < 0) {
			break;
		}
		else {

		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	timer();
	return 0;
}
