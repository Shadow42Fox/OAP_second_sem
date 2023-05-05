#include <iostream>
using namespace std;
void input(int size);
void output();
void find(char lastName[]);
typedef struct infoGuests {
	char soname[30];
	char name[30];
	long dateInto;
	long dateOut;
	int number;
} GUEST;
int number; FILE* f; errno_t err;

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice; char soname[16];
	do
	{
		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Вывод данных из файла\n";
		cout << "3.Поиск по фамилии\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите количество гостей: ";
			cin >> number;
			input(number);  break;
		case 2: output(); break;
		case 3: {  cout << "Введите фамилию: ";
			cin >> soname;
			find(soname); break;
		}
		case 0: exit(0);  break;
		}
	} while (choice != 0);
}

void input(int size)
{
	GUEST buf = { ' ', ' ', ' ', ' ', ' '};
	if (!fopen_s(&f, "base.txt", "ab"))
	{
		for (int p = 0; p < size; p++)
		{
					cout << "Enter soname: ";
					cin >> buf.soname;
					cout << "Enter name: ";
					cin >> buf.name;
					cout << "Enter dateInto: ";
					cin >> buf.dateInto;
					cout << "Enter dateOut: ";
					cin >> buf.dateOut;
					cout << "Enter number: ";
					cin >> buf.number;
					cout << endl;
			fwrite(&buf, sizeof(buf), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}

void output()
{
	GUEST buf;
	if (!fopen_s(&f, "base.txt", "rb"))
	{
		cout << "\nФамилия    Имя    Дата въезда	Дата выезда		Номер\n";
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			cout << buf.soname << "\t    " << buf.name << "\t    " << buf.dateInto << "\t    " << buf.dateOut << "\t    " << buf.number << endl;
			fread(&buf, sizeof(buf), 1, f);
		}
		cout << endl;
		fclose(f);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}

void find(char lastName[16])
{
	bool flag = false;  GUEST buf;
	if (!fopen_s(&f, "base.txt", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(lastName, buf.soname) == 0)   //сравнение строк
			{
				cout << "\nФамилия    Имя    Дата въезда	Дата выезда		Номер\n";
				cout << buf.soname << "\t    " << buf.name << "\t    " << buf.dateInto << "\t\t    " << buf.dateOut << "\t\t    " << buf.number << endl;
				flag = true; break;
			}
		}
		fclose(f);
		if (!flag) cout << "Ничего не найдено\n";
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}
