
#include "pch.h"
#include <iostream>

#include <locale.h>
#include <fstream>

using namespace std;


class spisok {
private:
	struct Node {
		int Data;
		Node *Next;

	};
	Node *Head = NULL;

public:

	// создание списка и заполнение из потока
	int create(istream& fin) {
		int data;
		Node *Current = new Node;
		while (fin >> data) {
			// если элемент первый, то меняем голову
			if (Head == NULL) {
				Head = Current;
				Current -> Next = NULL;
				Current->Data = data;

			}
			// иначе создаем текущий элемент
			else {
				Current->Next = new Node;
				Current = Current->Next;
				Current->Next = NULL;
				Current->Data = data;
			}
		}

		return 0;
	}

	// получить голову списка

	Node *GetHead() {
		return Head;
	}

	// вставить после ннного элемента

	int add(int n, int data) {
		int i = 0;

		// Если создаем первый элемент в списке, то меняем голову
		Node *Current = Head;
		if (Head == NULL) {
			Current = new Node;
			Head = Current;
			Current->Next = NULL;
			Current->Data = data;
			return 0;
		}

		// если n-ного эл-та не сущ, то нода будет добавлена вконец
		while ((i < n) && (Current->Next != NULL)) {
			i++;
			Current = Current->Next;
		}

		// пришли к n-ному эл-ту или последнему
		Node *NewE = new Node;
		NewE->Next = Current->Next;
		NewE->Data = data;
		Current->Next = NewE;
		return 0;

	}

	int deleten(int n) {
		Node *Current = Head;
		int i = 0;
		//конец и нет нужного элемента
		char isEnd = 0;
		if (n == 0) {
			Head = Current->Next;
			delete Current;
			return 0;
		}

		while (!isEnd) {
			if ((Current->Next == NULL))
				isEnd = 1;
			if ((i == n - 1))
				break;
			Current = Current->Next;
			i++;
		}
		if (isEnd) return 1;

		Node *delNode = Current->Next;
		if (Current->Next != NULL)
			Current->Next = Current->Next->Next;
		delete delNode;
		return 0;
	}

	//очистка памяти листа
	int Clear() {
		Node *Current = Head;
		while (Head != NULL) {
			Current = Head;
			Head = Head->Next;
			delete Current;
		}
		return 0;
	}

	int printList() {
		Node *Current = Head;
		if (Current == NULL) {
			cout << "List is empty" << endl;
			return 1;
		}
		while (Current != NULL) {
			cout << Current->Data << " ";
			Current = Current->Next;
		}
		cout << endl;
		return 0;
	}

	//чтение из элемента
	int Read(Node *Current) {
		return Current->Data;
	}

	//переход к нужному элементу
	Node * GoToELement(int n) {
		char isFound = 0;
		Node *Current = Head;
		int i;
		//пока можем бежим по массиву
		for (i = 0; i < n && Current->Next != NULL; i++) {
			Current = Current->Next;
		}
		if (i == n - 1) isFound = 1;
		//если такого элемента еще не создано, то вернуть нулпоинтер
		if (!isFound) return NULL;
		return Current;
	}
};

class spisok2 {
private:
	struct Node {
		int Data;
		Node *Next;
		Node *Prev;
	};
	Node *Head = NULL;

public:

};

int main() {
	std::cout << "Hello World!\n";
	ifstream fin;
	fin.open("iinput.dat");
	if (!fin.is_open()) {
		cout << "ERROR\n";
		return 3;
	}
	else {
		spisok a;
		a.create(fin);
		a.printList();
		a.add(3, 45);
		a.deleten(2);
		cout << endl << endl;
		a.printList();
		a.GoToELement(3);
		

	}
	fin.close();
}