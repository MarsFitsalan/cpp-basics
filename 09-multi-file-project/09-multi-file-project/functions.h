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
