#include <iostream>
#include <cmath>

using namespace std;

struct Negatives
{
    int first = -1;
    int second = -1;
};

void PrintArray(double *arr, const int kArraySize);
double FindArgMin(double *arr, const int kArraySize);
Negatives FindFirstSecondNegatives(double *arr, const int kArraySize);
double GetSum(double *arr, const int kArraySize, int begin, int end);
void TransformArray(double *arr, const int kArraySize);

int main()
{
    const int kArraySize = 10;
    double arr[kArraySize] = { 0, 1, -.2, 3, 4, 0, -6, .7, -8, .1 };
    
    cout << "Initial array:\n";
    PrintArray(arr, kArraySize);
    
    cout << "\nThe minimum element index of the array is: ";
    cout << FindArgMin(arr, kArraySize) << endl;
    
    cout << "\nSum of elements between the first and second negatives: ";
    Negatives negatives = FindFirstSecondNegatives(arr, kArraySize);
    if (negatives.second != -1)
    {
        if (negatives.first + 1 == negatives.second)
        {
            cout << "\nNo elements between the first and second negatives.";
        }
        else
        {
            cout << GetSum(arr, kArraySize, negatives.first, negatives.second);
        }
    }
    else
    {
        cout << "\nNo two negative elements were found.";
    }
    cout << endl;
    
    cout << "\nConverted array:\n";
    TransformArray(arr, kArraySize);
    PrintArray(arr, kArraySize);
    
    return 0;
}

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
