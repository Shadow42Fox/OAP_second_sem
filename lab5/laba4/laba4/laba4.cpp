//#include <iostream>
//using namespace std;
//
//void input(int size);
//void output();
//void find(char lastName[]);
//int number; FILE* f; errno_t err;
//
//enum jobTitle {
//	HR_manager = 1, personnel_officer, HR_inspector, 
//	labor_organization_engineer, timekeeper, 
//	labor_economist
//}jobt;
//
//typedef struct HRD {
//	char soname[16];
//	char name[16];
//	char special[16];
//	char subdiv[16];
//	int jobt;
//	int oklad;
//	struct DATA{
//		unsigned short int day : 8;
//		unsigned short int month : 8;
//		unsigned short int year : 16;
//	}date;
//}depart;
//
//
//int main() 
//{
//	setlocale(LC_ALL, "Russian");
//	int choice; char soname[16];
//	do
//	{
//		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
//		cout << "2.Вывод данных из файла\n";
//		cout << "3.Поиск по фамилии\n";
//		cout << "0.Выход из программы\n\n";
//		cout << "Введите номер операции: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1: cout << "Введите количество гостей: ";
//			cin >> number;
//			input(number);  break;
//		case 2: output(); break;
//		case 3: {  cout << "Введите фамилию: ";
//			cin >> soname;
//			find(soname); break;
//		}
//		case 0: exit(0);  break;
//		}
//	} while (choice != 0);
//}
//
//void input(int size)
//{
//	depart buf = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
//	if (!fopen_s(&f, "base.txt", "ab"))
//	{
//		for (int p = 0; p < size; p++)
//		{
//			cout << "Enter soname: ";
//			cin >> buf.soname;
//			cout << "Enter name: ";
//			cin >> buf.name;
//			cout << "Enter special: ";
//			cin >> buf.special;
//			cout << "Enter subdiv: ";
//			cin >> buf.subdiv;
//			cout << "Enter job title: \n1.- HR_manager, \n2. - personnel_officer, \n3. - HR_inspector, \n4. - labor_organization_engineer, \n5. - timekeeper,\n6. - labor_economist" << endl;
//			int ENTER;
//			cin >> ENTER;
//			buf.jobt = jobTitle(ENTER);
//			cout << "Enter date: ";
//			int day0 = 0, month0 = 0, year0 = 0;
//			cin >> day0; cin >> month0; cin >> year0;
//			buf.date.day = day0; buf.date.month = month0; buf.date.year = year0;
//			cout << endl;
//			fwrite(&buf, sizeof(buf), 1, f);
//		}
//		fclose(f);
//	}
//	else {
//		cout << "Ошибка открытия файла";
//		return;
//	}
//}
//
//void output()
//{
//	depart buf;
//	if (!fopen_s(&f, "base.txt", "rb"))
//	{
//		cout << "\nФамилия    Имя    Образование	Специальность	Подразделение	Должность	Оклад	Дата поступления\n";
//		fread(&buf, sizeof(buf), 1, f);
//		while (!feof(f))
//		{
//			cout << buf.soname << "\t    " << buf.name << "\t    " << buf.special << "\t    " << buf.subdiv << "\t    " << buf.jobt << "\t    " << buf.oklad << "\t    " << buf.date.day << "." << buf.date.month << "." << buf.date.year << endl;
//			fread(&buf, sizeof(buf), 1, f);
//		}
//		cout << endl;
//		fclose(f);
//	}
//	else
//	{
//		cout << "Ошибка открытия файла";
//		return;
//	}
//}
//
//void find(char lastName[16])
//{
//	bool flag = false;  depart buf;
//	if (!fopen_s(&f, "base.txt", "rb"))
//	{
//		while (!feof(f))
//		{
//			fread(&buf, sizeof(buf), 1, f);
//			if (strcmp(lastName, buf.soname) == 0)   //сравнение строк
//			{
//				cout << "\nФамилия    Имя    Образование	Специальность	Подразделение	Должность	Оклад	Дата поступления\n";
//				cout << buf.soname << "\t    " << buf.name << "\t    " << buf.special << "\t    " << buf.subdiv << "\t    " << buf.jobt << "\t    " << buf.oklad << "\t    " << buf.date.day << "." << buf.date.month << "." << buf.date.year << endl;
//				flag = true; break;
//			}
//		}
//		fclose(f);
//		if (!flag) cout << "Ничего не найдено\n";
//	}
//	else
//	{
//		cout << "Ошибка открытия файла";
//		return;
//	}
//}
//

#include <iostream>
#include <stdio.h>
using namespace std;

union table {
	char sonameOf[16];
	char nameExam[16];
	char dateOf[16];
}exams;

int main()
{
	FILE *Info;
	setlocale(LC_ALL, "Russian");
	fopen_s(&Info, "examInfo.txt", "w");
	cout << "Enter soname: ";
	cin >> exams.sonameOf;
	fprintf_s(Info, exams.sonameOf);
	fprintf_s(Info, " ");
	cout << "name of exam: ";
	cin >> exams.nameExam;
	fprintf_s(Info, exams.nameExam, " ");
	fprintf_s(Info, " ");
	cout << "Enter date of exam: ";
	cin >> exams.dateOf;
	fprintf_s(Info, exams.dateOf);
	fprintf_s(Info, " ");
	fclose(Info);
	FILE *examInfo;
	fopen_s(&examInfo, "examInfo.txt", "r");
	char Information[30];
	for (int i = 0; i < (sizeof(examInfo)*2); i++) 
	{
		fscanf_s(examInfo, "%c", &Information[i]);
		cout << Information[i];
	}
	fclose(examInfo);
}





//////Вариант2
 
 
 
//#include <iostream>
//using namespace std;
//
//void input(int size);
//void output();
//void find(char lastName[]);
//int number; FILE* f; errno_t err;
//
//enum Pol {
//	male = 1, famale
//}sex;
//
//typedef struct HumanInfo{
//	char soname[16];
//	char name[16];
//	char fathersname[16];
//	char adress[16];
//	int sex;
//	struct DATA{
//		unsigned short int day : 8;
//		unsigned short int month : 8;
//		unsigned short int year : 16;
//	}date;
//}infoTowner;
//
//
//int main() 
//{
//	setlocale(LC_ALL, "Russian");
//	int choice; char soname[16];
//	do
//	{
//		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
//		cout << "2.Вывод данных из файла\n";
//		cout << "3.Поиск по фамилии\n";
//		cout << "0.Выход из программы\n\n";
//		cout << "Введите номер операции: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1: cout << "Введите количество граждан: ";
//			cin >> number;
//			input(number);  break;
//		case 2: output(); break;
//		case 3: {  cout << "Введите фамилию: ";
//			cin >> soname;
//			find(soname); break;
//		}
//		case 0: exit(0);  break;
//		}
//	} while (choice != 0);
//}
//
//void input(int size)
//{
//	infoTowner buf = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
//	if (!fopen_s(&f, "base.txt", "ab"))
//	{
//		for (int p = 0; p < size; p++)
//		{
//			cout << "Enter soname: ";
//			cin >> buf.soname;
//			cout << "Enter name: ";
//			cin >> buf.name;
//			cout << "Enter special: ";
//			cin >> buf.fathersname;
//			cout << "Enter subdiv: ";
//			cin >> buf.adress;
//			cout << "Enter sex: \n1. - male\n2. - female" << endl;
//			int ENTER;
//			cin >> ENTER;
//			buf.sex = Pol(ENTER);
//			cout << "Enter date: ";
//			int day0 = 0, month0 = 0, year0 = 0;
//			cin >> day0; cin >> month0; cin >> year0;
//			buf.date.day = day0; buf.date.month = month0; buf.date.year = year0;
//			cout << endl;
//			fwrite(&buf, sizeof(buf), 1, f);
//		}
//		fclose(f);
//	}
//	else {
//		cout << "Ошибка открытия файла";
//		return;
//	}
//}
//
//void output()
//{
//	infoTowner buf;
//	if (!fopen_s(&f, "base.txt", "rb"))
//	{
//		cout << "\nФамилия    Имя    Отчество	Адрес	Пол		Дата Рождения\n";
//		fread(&buf, sizeof(buf), 1, f);
//		while (!feof(f))
//		{
//			cout << buf.soname << "\t    " << buf.name << "\t    " << buf.fathersname << "\t    " << buf.adress << "\t    " << buf.sex << "\t    " << buf.date.day << "." << buf.date.month << "." << buf.date.year << endl;
//			fread(&buf, sizeof(buf), 1, f);
//		}
//		cout << endl;
//		fclose(f);
//	}
//	else
//	{
//		cout << "Ошибка открытия файла";
//		return;
//	}
//}
//
//void find(char lastName[16])
//{
//	bool flag = false;  infoTowner buf;
//	if (!fopen_s(&f, "base.txt", "rb"))
//	{
//		while (!feof(f))
//		{
//			fread(&buf, sizeof(buf), 1, f);
//			if (strcmp(lastName, buf.soname) == 0)   //сравнение строк
//			{
//				cout << "\nФамилия    Имя    Отчество	Адрес	Пол		Дата Рождения\n";
//				cout << buf.soname << "\t    " << buf.name << "\t    " << buf.fathersname << "\t    " << buf.adress << "\t    " << buf.sex << "\t    " << buf.date.day << "." << buf.date.month << "." << buf.date.year << endl;
//				flag = true; break;
//			}
//		}
//		fclose(f);
//		if (!flag) cout << "Ничего не найдено\n";
//	}
//	else
//	{
//		cout << "Ошибка открытия файла";
//		return;
//	}
//}




//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//union table {
//	char numberOf[16];
//	char place[16];
//	char time[16];
//}exams;
//
//int main()
//{
//	FILE *Info;
//	setlocale(LC_ALL, "Russian");
//	fopen_s(&Info, "examInfo.txt", "w");
//	cout << "Enter number of train: ";
//	cin >> exams.numberOf;
//	fprintf_s(Info, exams.numberOf);
//	fprintf_s(Info, " ");
//	cout << "place where it arrives: ";
//	cin >> exams.place;
//	fprintf_s(Info, exams.place, " ");
//	fprintf_s(Info, " ");
//	cout << "Enter time of arrive: ";
//	cin >> exams.time;
//	fprintf_s(Info, exams.time);
//	fprintf_s(Info, " ");
//	fclose(Info);
//	FILE *examInfo;
//	fopen_s(&examInfo, "examInfo.txt", "r");
//	char Information[30];
//	for (int i = 0; i < (sizeof(examInfo)*2); i++) 
//	{
//		fscanf_s(examInfo, "%c", &Information[i]);
//		cout << Information[i];
//	}
//	fclose(examInfo);
//}



///////////Вариант3
 
 
 
//#include <iostream>
//using namespace std;
//
//void input(int size);
//void output();
//void find(char lastName[]);
//int number; FILE* f; errno_t err;
//
//enum subjects {
//	PE = 1, russian, belarussian, math, history, biology, astronomy
//}subj;
//
//typedef struct Pupils {
//	char soname[16];
//	char name[16];
//	int mark;
//	int middle_mark;
//	int subj;
//	struct CLAS {
//		unsigned char numb : 4;
//		unsigned char  letter: 4;
//	}Class;
//}school;
//
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	int choice; char soname[16];
//	do
//	{
//		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
//		cout << "2.Вывод данных из файла\n";
//		cout << "3.Поиск по фамилии\n";
//		cout << "0.Выход из программы\n\n";
//		cout << "Введите номер операции: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1: cout << "Введите количество человек: ";
//			cin >> number;
//			input(number);  break;
//		case 2: output(); break;
//		case 3: {  cout << "Введите фамилию: ";
//			cin >> soname;
//			find(soname); break;
//		}
//		case 0: exit(0);  break;
//		}
//	} while (choice != 0);
//}
//
//void input(int size)
//{
//	Pupils buf = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
//	if (!fopen_s(&f, "base.txt", "ab"))
//	{
//		for (int p = 0; p < size; p++)
//		{
//			cout << "Enter soname: ";
//			cin >> buf.soname;
//			cout << "Enter name: ";
//			cin >> buf.name;
//			cout << "Enter special: ";
//			cin >> buf.mark;
//			cout << "Enter subdiv: ";
//			cin >> buf.middle_mark;
//			cout << "Enter lesson: \n1. - PE, \n2. - russian, \n3. - belarussian, \n4. - math, \n5. - history, \n6. - biology, \n7. - astronomy" << endl;
//			int ENTER;
//			cin >> ENTER;
//			buf.subj = subjects(ENTER);
//			cout << "Enter date: ";
//			char numbers = ' ', letters = ' ';
//			cin >> numbers; cin >> letters;
//			buf.Class.numb = numbers; buf.Class.letter = letters;
//			cout << endl;
//			fwrite(&buf, sizeof(buf), 1, f);
//		}
//		fclose(f);
//	}
//	else {
//		cout << "Ошибка открытия файла";
//		return;
//	}
//}
//
//void output()
//{
//	Pupils buf;
//	if (!fopen_s(&f, "base.txt", "rb"))
//	{
//		cout << "\nФамилия    Имя    Отметка	Средняя отметка		Предмет		Класс\n";
//		fread(&buf, sizeof(buf), 1, f);
//		while (!feof(f))
//		{
//			cout << buf.soname << "\t    " << buf.name << "\t    " << buf.mark << "\t    " << buf.middle_mark << "\t    " << buf.subj << "\t    " << buf.Class.numb << buf.Class.letter << endl;
//			fread(&buf, sizeof(buf), 1, f);
//		}
//		cout << endl;
//		fclose(f);
//	}
//	else
//	{
//		cout << "Ошибка открытия файла";
//		return;
//	}
//}
//
//void find(char lastName[16])
//{
//	bool flag = false;  Pupils buf;
//	if (!fopen_s(&f, "base.txt", "rb"))
//	{
//		while (!feof(f))
//		{
//			fread(&buf, sizeof(buf), 1, f);
//			if (strcmp(lastName, buf.soname) == 0)   //сравнение строк
//			{
//				cout << "\nФамилия    Имя    Отметка	Средняя отметка		Предмет		Класс\n";
//				cout << buf.soname << "\t    " << buf.name << "\t    " << buf.mark << "\t    " << buf.middle_mark << "\t    " << buf.subj << "\t    " << buf.Class.numb << buf.Class.letter;
//				flag = true; break;
//			}
//		}
//		fclose(f);
//		if (!flag) cout << "Ничего не найдено\n";
//	}
//	else
//	{
//		cout << "Ошибка открытия файла";
//		return;
//	}
//}



//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//union table {
//	char base[16];
//	char soname[16];
//	char cost[16];
//}exams;
//
//int main()
//{
//	FILE *Info;
//	setlocale(LC_ALL, "Russian");
//	fopen_s(&Info, "examInfo.txt", "w");
//	cout << "Введите товар: ";
//	cin >> exams.base;
//	fprintf_s(Info, exams.base);
//	fprintf_s(Info, " ");
//	cout << "Введите фамилию покупателя: ";
//	cin >> exams.soname;
//	fprintf_s(Info, exams.soname, " ");
//	fprintf_s(Info, " ");
//	cout << "Введите цену товара: ";
//	cin >> exams.cost;
//	fprintf_s(Info, exams.cost);
//	fprintf_s(Info, " ");
//	fclose(Info);
//	FILE *examInfo;
//	fopen_s(&examInfo, "examInfo.txt", "r");
//	char Information[30];
//	for (int i = 0; i < (sizeof(examInfo)*2); i++) 
//	{
//		fscanf_s(examInfo, "%c", &Information[i]);
//		cout << Information[i];
//	}
//	fclose(examInfo);
//}




//////Вариант4



//#include <iostream>
//using namespace std;
//
//void input(int size);
//void output();
//void find(char lastName[]);
//int number; FILE* f; errno_t err;
//
//enum Pol {
//	male = 1, famale
//}sex;
//
//typedef struct HumanInfo{
//	char soname[16];
//	char name[16];
//	char fathersname[16];
//	char adress[16];
//	int sex;
//	struct DATA{
//		unsigned short int day : 8;
//		unsigned short int month : 8;
//		unsigned short int year : 16;
//	}date;
//}infoTowner;
//
//
//int main() 
//{
//	setlocale(LC_ALL, "Russian");
//	int choice; char soname[16];
//	do
//	{
//		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
//		cout << "2.Вывод данных из файла\n";
//		cout << "3.Поиск по фамилии\n";
//		cout << "0.Выход из программы\n\n";
//		cout << "Введите номер операции: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1: cout << "Введите количество граждан: ";
//			cin >> number;
//			input(number);  break;
//		case 2: output(); break;
//		case 3: {  cout << "Введите фамилию: ";
//			cin >> soname;
//			find(soname); break;
//		}
//		case 0: exit(0);  break;
//		}
//	} while (choice != 0);
//}
//
//void input(int size)
//{
//	infoTowner buf = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
//	if (!fopen_s(&f, "base.txt", "ab"))
//	{
//		for (int p = 0; p < size; p++)
//		{
//			cout << "Enter soname: ";
//			cin >> buf.soname;
//			cout << "Enter name: ";
//			cin >> buf.name;
//			cout << "Enter special: ";
//			cin >> buf.fathersname;
//			cout << "Enter subdiv: ";
//			cin >> buf.adress;
//			cout << "Enter sex: \n1. - male\n2. - female" << endl;
//			int ENTER;
//			cin >> ENTER;
//			buf.sex = Pol(ENTER);
//			cout << "Enter date: ";
//			int day0 = 0, month0 = 0, year0 = 0;
//			cin >> day0; cin >> month0; cin >> year0;
//			buf.date.day = day0; buf.date.month = month0; buf.date.year = year0;
//			cout << endl;
//			fwrite(&buf, sizeof(buf), 1, f);
//		}
//		fclose(f);
//	}
//	else {
//		cout << "Ошибка открытия файла";
//		return;
//	}
//}
//
//void output()
//{
//	infoTowner buf;
//	if (!fopen_s(&f, "base.txt", "rb"))
//	{
//		cout << "\nФамилия    Имя    Отчество	Адрес	Пол		Дата Рождения\n";
//		fread(&buf, sizeof(buf), 1, f);
//		while (!feof(f))
//		{
//			cout << buf.soname << "\t    " << buf.name << "\t    " << buf.fathersname << "\t    " << buf.adress << "\t    " << buf.sex << "\t    " << buf.date.day << "." << buf.date.month << "." << buf.date.year << endl;
//			fread(&buf, sizeof(buf), 1, f);
//		}
//		cout << endl;
//		fclose(f);
//	}
//	else
//	{
//		cout << "Ошибка открытия файла";
//		return;
//	}
//}
//
//void find(char lastName[16])
//{
//	bool flag = false;  infoTowner buf;
//	if (!fopen_s(&f, "base.txt", "rb"))
//	{
//		while (!feof(f))
//		{
//			fread(&buf, sizeof(buf), 1, f);
//			if (strcmp(lastName, buf.soname) == 0)   //сравнение строк
//			{
//				cout << "\nФамилия    Имя    Отчество	Адрес	Пол		Дата Рождения\n";
//				cout << buf.soname << "\t    " << buf.name << "\t    " << buf.fathersname << "\t    " << buf.adress << "\t    " << buf.sex << "\t    " << buf.date.day << "." << buf.date.month << "." << buf.date.year << endl;
//				flag = true; break;
//			}
//		}
//		fclose(f);
//		if (!flag) cout << "Ничего не найдено\n";
//	}
//	else
//	{
//		cout << "Ошибка открытия файла";
//		return;
//	}
//}