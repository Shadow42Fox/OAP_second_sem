#include <iostream>
#include<tchar.h>
#include<fstream>
using namespace std;

int def(int m, int n) {
	if (m == 1 || n == 1)
		return 1;
	if (n > m)
		return def(m, m);
	if (m == n)
		return def(m, m - 1) + 1;
	if (n < m)
		return def(m, n - 1) + def(m - n, n);
}
int sqr(float x, int l) {
	if (l == 1)
		return sqrt(1 + (x + 1));
	else
		return sqr(x + 1, l) * sqrt(1 + (l + x));
}



ofstream file1("file.txt");
int arr[256];
int A;
void ch(int k) {
	int i, j, t, p;
	for (i = 0; i < A - k; i++)
	{
		if (k < A - 2)
			ch(k + 1);
		else {
			for (p = 0; p < A; p++)
				file1 << arr[p];
			file1 << endl;
		}
		t = arr[k];
		for (j = k + 1; j < A; j++)
			arr[j - 1] = arr[j];
		arr[j - 1] = t;
	}

}
const int z = 5;
int a[z];
void perm(int k) {
	int q, j, t, p;
	for (q = 0; q < z - k; q++) {
		if (k < z - 2)
			perm(k + 1);
		else {
			for (p = 0; p < z; p++)
				cout << " " << a[p];
			cout << endl;
		}
		t = a[k];
		for (j = k + 1; j < z; j++)
			a[j - 1] = a[j];
		a[j - 1] = t;
	}
}
int counter = 0;
int posled(int v, int counter, int r)
{
	while (counter != 26)
	{
		cout << v << " ";
		return posled(v + r, counter + 1, r);
	}

}
int ct = 1;
int find(int ct, int v, int position, int r)
{
	while (ct != 26)
	{
		if (position == ct)
		{
			cout << endl;
			cout << "Number in position n: " << v << endl;
		}
		return find(ct + 1, v + r, position, r);
	}
}



int main() {
	int choice;
	for(;;)
	{
		cout << "Enter number:\n\t1. - Main task\n\t2. - 1 dop\n\t3. - 2 dop\n\t4. - 3 dop\n\t0. - Exit\n";
		cin >> choice;
		switch(choice)
		{
		case 1:
		{
			int m, n;
			cout << "Enter m, n: ";
			cin >> m; cin >> n;
			cout << "\nResult: " << def(m, n) << endl << endl;
			float x = 1;
			int l;
			cout << "Enter l: ";
			cin >> l;
			cout << "\nAnswer: " << sqr(x, l) << endl << endl;
		}
		case 2: 
			cout << "Enter number:";
			cin >> A;
			cout << endl;
			int i;
			for (i = 0; i < A; i++)
				arr[i] = i + 1;
			ch(0);
			file1.close();
			cout << "Data was added to file." << endl;
		case 3:
			int q;
			for (q = 0; q < z; q++)
				a[q] = q + 1;
			perm(0);
			break;
		case 4:
			int position, v, r;
			cout << "Enter first position:";
			cin >> v;
			cout << endl;
			cout << "Enter number to add for position:";
			cin >> r;
			cout << endl;
			cout << "Enter n:";
			cin >> position;
			cout << endl;
			cout << "List:";
			posled(v, counter, r);
			find(ct, v, position, r);
			break;
		case 0: exit(1); break;
		}
	}
}