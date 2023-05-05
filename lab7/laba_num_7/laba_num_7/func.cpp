#include "Header.h"

void push(struct Stack*& MyStack) {
	char chislo[9];
	cout << "для выхода нажмите q\n Вводите элементы ";
	while (cin >> chislo && *chislo != 'q') {
		Stack* data = new Stack;
		data->number = atoi(chislo);
		data->next = MyStack->head;
		MyStack->head = data;
	}
	cout << "Стек записан!";
	return;
}

void clearStack(Stack*& MyStack) {
	if (!MyStack->head) { cout << "Стек пуст!\n"; }
	else {
		while (MyStack->head) {
			Stack* delStack = MyStack->head;
			MyStack->head = MyStack->head->next;
			delete delStack;
		}
		cout << "Стек очищен!\n";
	}
}


void showStack(Stack*& MyStack) {
	Stack* data = MyStack->head;
	if (!MyStack->head) { cout << "стек пуст!\n"; }
	else { cout << " \n"; }
	while (data != NULL) {
		cout << data->number << "\n";
		data = data->next;
	}
}

void showStack2(Stack* st) {
	if (st == NULL)
	{
		cout << "пустo" << endl;
		return;
	}
	int n = 0;
	while (st != NULL)
	{
		cout << n << " " << st->number << endl;
		n++;
		st = st->next;
	}
}


void find(Stack* MySt1, Stack* MySt2, Stack* MySt3) {
	if (!MySt1->head) { cout << "стек пуст!\n"; }
	else {
		Stack* MyStack1 = new Stack;
		MyStack1->head = MySt1->head;
		int a[20];
		int n = 0;
		while (MyStack1->head) {
			a[n] = MyStack1->head->number;
			MyStack1->head = MyStack1->head->next;
			n++;
		}

		int b[20], c[20];
		int k = 0, l = 0;

		for (int i = 0; i < n; i++) {
			if (a[i] > 50) {
				b[k] = a[i];
				k++;
			}
			if (a[i] < 50) {
				c[l] = a[i];
				l++;
			}
		}

		for (int i = 0; i < k; i++) {
			Stack* data = new Stack;
			data->number = b[i];
			data->next = MySt2->head;
			MySt2->head = data;
		}

		for (int i = 0; i < l; i++) {
			Stack* data = new Stack;
			data->number = c[i];
			data->next = MySt3->head;
			MySt3->head = data;
		}
	}
}

void WriteInFile(Stack* MySt, string fileName) {
	if (!MySt->head) { cout << "стек пуст!\n"; }
	else {
		ofstream FILE;
		FILE.open(fileName);
		Stack* MyStack = new Stack;
		MyStack->head = MySt->head;
		while (MyStack->head) {
			FILE << "\n\t\t" << MyStack->head->number;
			MyStack->head = MyStack->head->next;
		}
		cout << fileName << endl;

	}
}


void ReadFromFile(Stack* MySt, string fileName) {
	int indicate;
	ifstream FILE;
	FILE.open(fileName, ofstream::app);
	if (!(FILE >> indicate)) { cout << "Стек пуст\n"; }
	else {
		while (indicate) {
			Stack* data = new Stack;
			data->number = indicate;
			data->next = MySt->head;
			MySt->head = data;
			if (!(FILE >> indicate)) { break; }
		}
	}
	FILE.close();
}

void dop2(ifstream& f, Stack* MySt) {
	f.open("file.txt");
	if (f.fail())
	{
		cout << "\n Ошибка открытия файла";
		return;
	}
	Stack* pdop2 = nullptr;
	char str[256];
	while (f.getline(str, 256)) {
		cout << str << endl;
		pash(pdop2, strlen(str));
	}
	showStack2(pdop2);
	findMin(pdop2);
	f.close();
}

void findMin(Stack* st) {
	if (st == NULL)
	{
		cout << "пустo" << endl;
		return;
	}
	int minSize = st->number, index = 0;
	int n = 1;
	st = st->next;
	while (st != NULL)
	{
		if (minSize >= st->number)
		{
			index = n;
			minSize = st->number;
		}
		n++;
		st = st->next;
	}
	cout << "№" << index << " min = " << minSize << endl;
}

void pash(Stack*& st, int d)
{
	Stack* pv = new Stack;
	pv->number = d;
	pv->next = st;
	st = pv;
}

int pop(Stack*& st)
{
	if (st != NULL)
	{
		int tmp = st->number;
		Stack* pv = st;
		st = st->next;
		delete pv;
		return tmp;
	}
	else
	{
		cout << "пусто" << endl;
		return 0;
	}

}

void dop1() {
	Stack* dop1 = nullptr;
	char str[256], str2[256];
	int n;
	cout << "Введите строку" << endl;
	cin >> str;
	n = strlen(str);
	if (n % 2 != 0)
	{
		cout << "неверная строка" << endl;
		return;
	}
	int i = 0;
	while (str[i] != '\0')
	{
		pash(dop1, int(str[i]));
		i++;
	}
	for (int j = n / 2; j < n; j++)
		str2[j] = char(pop(dop1));
	for (int j = 0; j < n / 2; j++)
		str2[j] = char(pop(dop1));
	str2[n] = '\0';
	cout << str2 << endl;
}

void dop3(Stack* MySt1, Stack* MySt2, Stack* MySt3) {
	if (!MySt1->head) { cout << "Ñòåê ïóñò!\n"; }
	else {
		Stack* MyStack1 = new Stack;
		MyStack1->head = MySt1->head;
		int a[20];
		int n = 0;
		while (MyStack1->head) {
			a[n] = MyStack1->head->number;
			MyStack1->head = MyStack1->head->next;
			n++;
		}

		int b[20], c[20];
		int k = 0, l = 0;

		for (int i = 0; i < n; i++) {
			if (a[i] > 0) {
				b[k] = a[i];
				k++;
			}
			if (a[i] < 0) {
				c[l] = a[i];
				l++;
			}
		}

		for (int i = 0; i < k; i++) {
			Stack* data = new Stack;
			data->number = b[i];
			data->next = MySt2->head;
			MySt2->head = data;
		}

		for (int i = 0; i < l; i++) {
			Stack* data = new Stack;
			data->number = c[i];
			data->next = MySt3->head;
			MySt3->head = data;
		}
	}
}
