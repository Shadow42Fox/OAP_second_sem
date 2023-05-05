#include "Header.h"

void menu() {
	cout << "1. - Запись чисел в стек\n2. - Вывод положительных и отрицательных чисел\n3. - Очистка стека\n4. - Запись стека в файл\n5. - Считать стек из файла\n6. - Доп1\n7. - Вывод стека с числами больше 50 и остальных\n8. - Доп2\n0. - Exit\n\nEnter number: ";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int number, choice;
	Stack* MyStack1 = new Stack;
	Stack* MyStack2 = new Stack;
	Stack* MyStack3 = new Stack;

	MyStack1->head = nullptr;
	MyStack2->head = nullptr;
	MyStack3->head = nullptr;

	while (true) {
		menu();
		cin >> choice;
		ifstream infile;
		switch (choice) {
		case 0: return 0;
		case 1:
			system("cls");
			cout << "Введите элементы первого стека:" << endl;
			push(MyStack1);
			system("pause");
			system("cls");
			break;
		case 2: {
			system("cls");
			dop3(MyStack1, MyStack2, MyStack3);
			cout << "Элементы первого стека:" << endl;
			showStack(MyStack1);
			cout << "Элементы второго стека:" << endl;
			showStack(MyStack2);
			cout << "Элементы третьего стека:" << endl;
			showStack(MyStack3);
			system("pause");
			system("cls");
		} break;
		case 3:
			system("cls");
			clearStack(MyStack1);
			showStack(MyStack1);
			system("pause");
			system("cls");
			break;
		case 4:
			WriteInFile(MyStack1, "Data1.txt");
			WriteInFile(MyStack2, "Data2.txt");
			WriteInFile(MyStack3, "Data3.txt");
			break;
		case 5:
			system("cls");
			cout << "Элементы первого стека:" << endl << endl;
			showStack(MyStack1);
			cout << "Элементы второго стека:" << endl;
			showStack(MyStack2);
			cout << "Элементы третьего стека:" << endl;
			showStack(MyStack3);
			system("pause");
			system("cls");
			break;
		case 6: {
			system("cls");
			dop1();
		}break;
		case 7:
			system("cls");
			find(MyStack1, MyStack2, MyStack3);
			cout << "Элементы стека:" << endl;
			showStack(MyStack1);
			cout << "Элементы стека больше 50:" << endl;
			showStack(MyStack2);
			cout << "Остальные элементы стека:" << endl;
			showStack(MyStack3);
			system("pause");
			system("cls");
			break;
		case 8:
		{
			dop2(infile, MyStack1);
		}
		break;
		}
	}
}

