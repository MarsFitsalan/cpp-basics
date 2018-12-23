#include "functions.h"

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
