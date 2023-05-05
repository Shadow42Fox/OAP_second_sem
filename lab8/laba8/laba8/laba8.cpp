#include "Header.h"
using namespace std;


void main()
{
	qmanager* My_Queue = new qmanager;
	My_Queue->head = NULL;
	My_Queue->tail = NULL;
	int key;
	do {
		cout << "Enter number:\n\t1. - Add Elements\n\t2. - Delete element\n\t3. - Show Queue\n\t4. - Enter task\n\t0. - Exit\n";
		cin >> key;
		switch (key) {
		case 1: push(My_Queue); break;
		case 2: pop(My_Queue); break;
		case 3: showQueue(My_Queue); break;
		case 4: task(My_Queue); break;
		case 0:  exit;
		}
	} while (key != 0);
}
