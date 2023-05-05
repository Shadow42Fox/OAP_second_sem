#pragma once
#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

struct Stack {
	int number;
	Stack* head;
	Stack* next;
};

void menu();
void push(struct Stack*& MyStack);
void pash(Stack*& st, int d);
void findMin(Stack* st);
void clearStack(struct Stack*& MyStack);
void showStack(Stack*& MyStack);
void showStack2(Stack* st);
void clearStack(Stack*& MyStack);
void find(Stack* MySt1, Stack* MySt2, Stack* MySt3);
void WriteInFile(Stack* MySt, string fileName);
void ReadFromFile(Stack* MySt, string fileName);
void dop2(ifstream& f, Stack* MySt);
int pop(Stack*& st);
void dop1();
void dop3(Stack* MySt1, Stack* MySt2, Stack* MySt3);


