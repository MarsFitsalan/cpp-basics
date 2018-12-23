#include "functions.h"

void PrintArray(double *arr, const int kArraySize)
{
    for (int i = 0; i < kArraySize; i++)
        cout << "[" << i << "] = " << arr[i] << endl;
}

double FindArgMin(double *arr, const int kArraySize)
{
    int arg_min = 0;
    for (int i = 1; i < kArraySize; i++)
        if (arr[i] < arr[arg_min])
            arg_min = i;
    return arg_min;
}

Negatives FindFirstSecondNegatives(double *arr, const int kArraySize)
{
    Negatives negatives;
    for (int i = 0; i < kArraySize; i++)
    {
        if (arr[i] < 0 && negatives.first == -1)
        {
            negatives.first = i;
        }
        else if (arr[i] < 0 && negatives.first != -1)
        {
            negatives.second = i;
            break;
        }
    }
    return negatives;
}

double GetSum(double *arr, const int kArraySize, int begin, int end)
{
    double sum = 0.0;
    for (int i = begin + 1; i < end; i++)
        sum += arr[i];
    return sum;
}

void TransformArray(double *arr, const int kArraySize)
{
    for (int i = 0; i < kArraySize - 1; i++)
        for (int j = 0; j < kArraySize - i - 1; j++)
            if ((abs(arr[j]) > 1) && (abs(arr[j + 1]) <= 1))
                swap(arr[j], arr[j + 1]);
}
