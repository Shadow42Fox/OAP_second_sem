#include "Header.h";

using namespace std;

void push(qmanager* My_Queue){
	cout << "Enter symbol, press 'q' for exit:\n";
	char n;
	do {
		cin >> n;
		if (n != 'q'){
			Queue* p = new Queue;
			p->symbol = n;

			if (My_Queue->head == NULL) {
				My_Queue->head = My_Queue->tail = p;
				p->next = NULL;
			}
			else {
				p->next = My_Queue->tail;
				My_Queue->tail = p;
			}
		}
	} while (n != 'q');
}

void showQueue(qmanager* My_Queue) {
	Queue* p = new Queue;
	p = My_Queue->tail;
	int size = 0;
	while (p) {
		cout << p->symbol << "-->";
		p = p->next;
		size++;
	}
	cout << "NULL\t" << "Size of Queue: " << size <<endl;
}
void pop(qmanager* My_Queue) {
	Queue* p = new Queue;
	Queue* prev = new Queue;
	p = My_Queue->tail;
	prev = NULL;
	while (p->next && p->next->next)
	{
		p = p->next;
	}
	if (My_Queue->head == My_Queue->tail) {
		My_Queue->tail = My_Queue->head = 0;
		delete(p);
	}
	else {
		My_Queue->head = p;
		prev = p;
		p = p->next;
		cout << "delete: " << p->symbol << endl;
		prev->next = NULL;
		delete(p);
	}
}
void task(qmanager* My_Queue) {
	cout << "Enter symbol, press 'q' for exit:\n";
	char n;
	do {
		cin >> n;
		if (n != 'q') {
			Queue* p = new Queue;
			p->symbol = n;

			if (My_Queue->head == NULL) {
				My_Queue->head = My_Queue->tail = p;
				p->next = NULL;
			}
			else {
				p->next = My_Queue->tail;
				My_Queue->tail = p;
			}
		}
	} while (n != 'q');

	for (int k = 0; k < 2; k++) {
		Queue* p = new Queue;
		Queue* prev = new Queue;
		p = My_Queue->tail;
		prev = NULL;
		while (p->next && p->next->next)
		{
			p = p->next;
		}
		if (My_Queue->head == My_Queue->tail) {
			My_Queue->tail = My_Queue->head = 0;
			delete(p);
		}
		else {
			My_Queue->head = p;
			prev = p;
			p = p->next;
			cout << "delete: " << p->symbol << endl;
			prev->next = NULL;
			delete(p);
		}
	}


	Queue* p = new Queue;
	p = My_Queue->tail;
	int size = 0;
	while (p) {
		cout << p->symbol << "-->";
		p = p->next;
		size++;
	}
	cout << "NULL\t" << "Size of Queue: " << size << endl;
}