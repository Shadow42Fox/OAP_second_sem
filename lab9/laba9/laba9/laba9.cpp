﻿#include <iostream>
#include <fstream>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};
//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
Address* setElement() // Создание элемента и ввод его значений с клавиатуры
{
	Address* temp = new Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	cin >> temp->name;
	cout << "Введите город: ";
	cin >> temp->city;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast) //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address** phead) // Поиск имени в списке
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address** phead, Address** plast)// Удаление элемента по имени
{
	struct Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
	}
}
//-----------------------------------------------------------
void writeToFile(Address** phead) //Запись в файл
{
	struct Address* t = *phead;
	ofstream file1("Lip.txt");
	if (file1.fail())
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		file1 << t->name << " " << t->city << endl;
		t = t->next;
	}
	file1.close();
}
//---------------------------------------------------------------
void fromFile(Address** phead)
{

	char buf[256];
	ifstream file2("Lip.txt");
	if (file2.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (!file2.eof())
	{
		file2.getline(buf, 256);
		if (strlen(buf))
			cout << " " << buf;
		cout << endl;
	}

	file2.close();
}
//-----------------------------------------------------------
void delm(Address** phead, Address** plast, int m)
{

	Address* t = *phead;
	Address* g = *phead;
	Address* k = *phead;
	while (t)
	{
		g = t;
		while (g->next)
		{
			if (!strcmp(t->name, g->next->name) || (!strcmp(t->city, g->next->city))) {
				k = g->next;
				g->next = k->next;
				delete k;
			}
			else g = g->next;
		}
		t = t->next;
	}
}
//-----------------------------------------------------------
int main(void)
{
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	int choice;
	char s[80]; int c;
	cout << endl;
	

	while (true)
	{
		cout << "1. - Ввод адреса\n2. - Удаление имени\n3. - Вывод на экран\n4. - Поиск\n5. - В файл\n6. - Из файла\n7. - функция удаления повторяющихся\n0. - Выход\n\n" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: exit(0);
		case 1: insert(setElement(), &head, &last);
			break;
		case 2: { char dname[NAME_SIZE];
			cout << "Введите имя: ";
			cin >> dname;
			delet(dname, &head, &last);
		}
			  break;
		case 3: outputList(&head, &last);
			break;
		case 4: { char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin >> fname;
			find(fname, &head);
		}
			  break;
		case 5: {
			writeToFile(&head);
		}
			  break;
		case 6: {
			fromFile(&head);
		}
			  break;
		case 7: {
			int m = 1;
			delm(&head, &last, m);
		}
			  break;
		default: exit(1);
		}
	}
	return 0;
}
