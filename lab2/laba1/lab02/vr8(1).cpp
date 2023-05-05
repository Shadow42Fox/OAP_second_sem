#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("arr.txt", "r");
    if (file == NULL)
        fprintf(stderr, "Cannot open file");


    int size, i, b;

    fscanf(file, "%d", &size); //1-й элемент файла - количество элементов в массиве
    int* arr = (int*)malloc(size * sizeof(int));
    for (i = 0; i < size; ++i)
    {
        fscanf(file, "%d", &arr[i]);
    }
    fflush(file);
    fclose(file);

    file = fopen("arr.txt", "w");
    if (file == NULL)
        fprintf(stderr, "Cannot write file");
    fprintf(file, "%d ", (size));

    for (i = 0; i < size / 2; i++) {
        b = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = b;
    }
    for (i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
    free(arr);
    return 0;
}