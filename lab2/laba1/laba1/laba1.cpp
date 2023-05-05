#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
using namespace std;
int zadanie1()
{
	setlocale(LC_CTYPE, "Russian");
	FILE* fA;
	FILE* fB;
	FILE* fC;
	int a[2][3], b[3][2], c[3][3];
	fA = fopen("fA.txt", "r");
	fB = fopen("fB.txt", "r");
	fC = fopen("fC.txt", "w");
	cout << "Задание 1\n";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			fscanf(fA, "%d", &a[i][j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++)
			fscanf(fB, "%d", &b[i][j]);
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				c[i][j] = a[i][j] * b[i][j];
			}
			fprintf(fC, "c[%d][%d] %d\t", i, j, c[i][j]);
			cout << "c[" << i << "][" << j << "] " << c[i][j] << "   ";
		}
		fprintf(fC, "\n");
		cout << endl;
	}
	fclose(fA);
	fclose(fB);
	fclose(fC);
	return 0;
}

int zadanie2(){
	FILE* f;
	int a[8], b[8];
	int K;
	cout << "\n\nЗадание 2\n";
	cout << "Введите K: ";
	cin >> K;
	f = fopen("f.txt", "r");
	for (int i = 0; i < 8;i++) {
		fscanf(f, "%d", &a[i]);
	}
	cout << "Массив:\n";
	for (int i = 0; i < 8; i++) {
		printf("%d ", a[i]);
	}
	cout << "\nЧисла массива, которые делятся на " << K << ":" << endl;
	for (int i = 0, j = 0; j = 0, i < 8; i++) {
		if (a[i] % K == 0) {
			b[j] = a[i];
			cout << b[j] << " ";
			j++;
		}
	}
	fclose(f);
	return 0;
}
void main() {
	zadanie1();
	zadanie2();
}
