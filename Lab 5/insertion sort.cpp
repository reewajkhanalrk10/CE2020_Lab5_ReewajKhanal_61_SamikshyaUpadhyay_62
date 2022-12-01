#include "sort.h"
#include <iostream>
using namespace std;

void insertionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int a = 0;
        for (int j = 0; j <= i; j++)
        {
            if (arr[i + 1] < arr[j])
            {
                a = 1;
            }
            if (a == 1)
            {
                arr[j] = arr[j] ^ arr[i + 1];
                arr[i + 1] = arr[j] ^ arr[i + 1];
                arr[j] = arr[j] ^ arr[i + 1];
            }
        }
    }
    return;
};