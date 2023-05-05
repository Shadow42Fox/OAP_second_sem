#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>



struct Item
{
	int number;             //информационный элемент
	Item* head;	 //вершина стека 
	Item* next;		 //указатель на следующий элемент
};

void menu();
void vivod(Item*);        //прототип
void addElem(Item*&, int);  //прототип
int deleteNum(Item*&, int);
void find(Item*, Item*, Item*);
void writeInFile(Item*);
void readInFile(Item*);



void menu() {
	using namespace std;
	cout << "1. - add to list of number\n2. - print stack\n3. - clean stack\n4. - print positive and negative numbers\n5. - add stack to file\n6. - read stack in file\n0. - Exit.\n";
}

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");
	int choice, num;
	
	Item* pnum = new Item;
	Item* Stack1 = new Item;
	Item* Stack2 = new Item;

	Stack2->head = NULL;
	Stack1->head = NULL;
	pnum->head = NULL;


	for (;;)
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 0: return 0;
		case 1: cout << "Enter element of stack: " << endl;
			cin >> num;
			addElem(pnum, num);
			break;
		case 2: vivod(pnum);
		case 3: cout << "Enter element of stack: " << endl;
			cin >> num;
			deleteNum(pnum, num);
			cout << "Stack has been deleted";
			break;
		case 4: find(pnum, Stack1, Stack2);
			break;
		case 5: writeInFile(pnum);
			cout << "Info has been added to file";
			break;
		case 6: readInFile(pnum);
			break;
		}
	}
}



using namespace std;

void addElem(Item*& p, int value)
{
	Item* newP = new Item;
	newP->number = value;
	newP->next = p;
	p = newP;
}

int deleteNum(Item*& p, int value)
{
	Item* previos, * current, * temp;
	if (value == p->number)
	{
		temp = p;
		p = p->next;
		delete temp;
		return value;
	}
	else
	{
		previos = p;
		current = p->next;
		while (current != NULL && current->number != value)
		{
			previos = current;
			current = p->next;
		}
		if (current == NULL)
		{
			temp = current;
			previos->next = current->next;
			free(temp);
			return value;
		}
	}
	return 0;
}

void vivod(Item* p)
{
	Item* e = p->head;
	cout << "Stack:" << endl;
	int a;
	while (p != NULL) {
		a = e->number;
		cout << "-->" << a;
		e = e->next;
	}
	cout << "-->NULL" << endl;
}

void find(Item* pnum, Item* St1, Item* St2)
{
	if (!pnum->head)
		cout << "Error(";
	else
	{
		Item* Stack1 = new Item;
		Stack1->head = pnum->head;
		int a[20];
		int n = 0;
		while (Stack1->head)
		{
			a[n] = Stack1->head->number;
			Stack1->head = Stack1->head->next;
			n++;
		}
		int b[20], c[20];
		int k = 0, l = 0;

		for (int i = 0; i < n; i++)
		{
			if (a[i] > 0)
			{
				b[k] = a[i];
				k++;
			}
			if (a[i] < 0)
			{
				c[l] = a[i];
				l++;
			}
		}
		for (int i = 0; i < k; i++)
		{
			Item* negative = new Item;
			negative->number = b[i];
			negative->next = St1->head;
			St1->head = negative;
		}
		for (int i = 0; i < l; i++)
		{
			Item* positive = new Item;
			positive->number = c[i];
			positive->next = St2->head;
			St2->head = positive;
		}
	}
}
void writeInFile(Item* p)
{
	if (!p->head)
		cout << "Error";
	else
	{
		FILE* fa;
		fa = fopen("data.txt", "a");
		Item* data = new Item;
		data->head = p->head;
		while (data->head)
		{
			fprintf(fa, "%d \t", data->head->number);
			data->head = data->head->next;
		}
		fclose(fa);
	}
}
void readInFile(Item* p)
{

	int indicate;
	ifstream FILE;
	FILE.open("data.txt", ofstream::app);
	if (!(FILE >> indicate)) { cout << "Error!\n"; }
	else {
		while (indicate) {
			Item* data = new Item;
			data->number = indicate;
			data->next = p->head;
			p->head = data;
			if (!(FILE >> indicate)) { break; }
		}
	}
	FILE.close();
}