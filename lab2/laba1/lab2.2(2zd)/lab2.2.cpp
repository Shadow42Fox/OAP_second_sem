
#include <stdio.h>
#include <iostream>
using namespace std;

void main()
{
    setlocale(LC_CTYPE, "Russian");

    int n, m1, m2;
    int b = 1;
    FILE* A, * B, * C;
    cout << "Введите размер матрицы: "; cin >> n;

    errno_t err1, err2;
    err1 = fopen_s(&A, "A.txt", "w");
    if (err1 != 0)
    {
        perror("Ошибка открытия a.txt");
        return;
    }

    err2 = fopen_s(&B, "B.txt", "w");
    if (err2 != 0)
    {
        perror("Ошибка открытия b.txt");
        return;
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                fprintf(A, "%d ", n);
                fprintf(A, "\n");
            }
            fprintf(A, "%d ", rand() % 10);
        }
        fprintf(A, "\n");
    }
    fclose(A);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (i == 0 && j == 0)
            {
                fprintf(B, "%d ", b);
                fprintf(B, "\n");
            }
            fprintf(B, "%d ", rand() % 10);
        }
        fprintf(B, "\n");
    }
    fclose(B);


    fopen_s(&A, "A.txt", "r");
    fopen_s(&B, "B.txt", "r");
    fopen_s(&C, "C.txt", "w");
    fscanf_s(A, "%d", &m1);
    fscanf_s(B, "%d", &m2);
    fprintf(C, "%d ", m1);
    fprintf(C, "\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf_s(A, "%d", &m1);
            fscanf_s(B, "%d", &m2);
            fprintf(C, "%d ", m1 * m2);
        }
        fprintf(C, "\n");
    }
    fclose(A);
    fclose(B);
    fclose(C);
    return;
}