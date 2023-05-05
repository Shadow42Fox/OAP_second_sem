#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

int firstTask() {
	char stroka[50];
	char result[50];
	ofstream thisString1("thisIsString.txt");
	cout << "Enter string:" << endl;
	cin.getline(stroka, 50);
	cout << "\nyour string:  " << stroka << endl;
	thisString1 << stroka;
	ifstream outString("thisIsString.txt");
	outString.getline(stroka, 50);
	cout << "Massive of numbers: ";
	for (int i = 0, j = 0; i < 50; i++) {
		if (stroka[i] <= '9' && stroka[i] >= '0')
		{
			if (stroka[i] % 2 != 0)
			{
				cout << stroka[i];
				result[j] = stroka[i];
				j++;
			}
		}
	}
	ofstream lastString("ResultString.txt");
	lastString << result;
	lastString.close();
	return 0;
}

int secondTask() {
	char firstString[50];
	char secondString[50];
	int secondlen = 0;
	ofstream readString("readString.txt");
	cout << "\n\nEnter string:" << endl;
	cin.getline(firstString, 50);
	readString << firstString;
	readString.close();
	cout << "Lenth of this string(bites): " << (strlen(firstString)*8) << "\nSecond string: ";
	for (int i = 0, j = 0, k = 0; i < strlen(firstString); i++)
	{
		if (firstString[i] == ' ')
		{
			j++;
		}
		while (j % 2 != 0 && (i != strlen(firstString))) {
			cout << firstString[i];
			secondString[k] = firstString[i];
			i++;
			k++;
			secondlen = k;
			if (firstString[i] == ' ')
			{
				j++;
			}
		}
	}
	cout << "\nLenth of this string(bites): " << (secondlen*8);
	ofstream writeString("writeString.txt");
	writeString << secondString;
	writeString.close();
	return 0;
}

void main(){
	firstTask();
	secondTask();
}

