#pragma once
#include <iostream>

struct Queue {
	char symbol;
	Queue* next;
};

struct qmanager {
	Queue* head;
	Queue* tail;
};

bool empty(qmanager*);
void push(qmanager*);
void showQueue(qmanager*);
void pop(qmanager*);
void task(qmanager*);