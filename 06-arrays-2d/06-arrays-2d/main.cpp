#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int** ReadMatrix(string file_name, int num_rows, int num_cols);
void PrintMatrix(int** matrix, int num_rows, int num_cols);
int* ComputeCharacteristics(int** matrix, int num_rows, int num_cols);
void SortMatrix(int** matrix, int num_rows, int num_cols);
int SumColumn(int** matrix, int num_rows, int column);
void PrintColumnsSums(int** matrix, int num_cols, int num_rows);

int main()
{
    int num_rows = 3;
    int num_cols = 4;
    
    string path = "/Users/marsfitsalan/Desktop/";
    path += "cpp-basics/06-arrays-2d/06-arrays-2d/matrix.txt";
    int** matrix = ReadMatrix(path, num_rows, num_cols);
    if (!matrix) return 1;
    
    cout << "Initial matrix:\n";
    PrintMatrix(matrix, num_rows, num_cols);
    cout << endl;
    
    cout << "\nSorted matrix:\n";
    SortMatrix(matrix, num_rows, num_cols);
    PrintMatrix(matrix, num_rows, num_cols);
    cout << endl;
    
    PrintColumnsSums(matrix, num_rows, num_cols);
    
    for (int i = 0; i < num_rows; i++) delete[] matrix[i];
    delete[] matrix;
    
    return 0;
}

int** ReadMatrix(string file_name, int num_rows, int num_cols)
{
    ifstream fin(file_name);
    if (!fin.is_open())
    {
        cout << "\nCan't open file " << file_name << "!\n";
        return nullptr;
    }
    
    int** matrix = new int*[num_rows];
    for (int i = 0; i < num_rows; i++)
    {
        matrix[i] = new int[num_cols];
        for (int j = 0; j < num_cols; j++)
            fin >> matrix[i][j];
    }
    fin.close();
    return matrix;
}

void PrintMatrix(int** matrix, int num_rows, int num_cols)
{
    cout << string(5 * num_cols + 1, '-');
    for (int i = 0; i < num_rows; i++)
    {
        cout << "\n|";
        for (int j = 0; j < num_cols; j++)
            cout << setw(3) << matrix[i][j] << setw(2) << "|";
    }
    cout << endl << string(5 * num_cols + 1, '-');
    
    int* characteristics = ComputeCharacteristics(matrix, num_rows, num_cols);
    cout << "\n|";
    for (int j = 0; j < num_cols; j++)
        cout << setw(3) << characteristics[j] << setw(2) << "|";
    cout << endl << string(5 * num_cols + 1, '-');
    delete[] characteristics;
}

int* ComputeCharacteristics(int** matrix, int num_rows, int num_cols)
{
    int* characteristics = new int[num_cols];
    for (int j = 0; j < num_cols; j++)
    {
        characteristics[j] = 0;
        for (int i = 0; i < num_rows; i++)
            if ((matrix[i][j] < 0) && (matrix[i][j] % 2 != 0))
                characteristics[j] += abs(matrix[i][j]);
    }
    return characteristics;
}

void SortMatrix(int** matrix, int num_rows, int num_cols)
{
    int* characteristics = ComputeCharacteristics(matrix, num_rows, num_cols);
    
    for (int i = 0; i < num_cols - 1; i++)
        for (int j = 0; j < num_cols - i - 1; j++)
            if (characteristics[j] > characteristics[j + 1])
            {
                swap(characteristics[j], characteristics[j + 1]);
                for (int k = 0; k < num_rows; k++)
                    swap(matrix[k][j], matrix[k][j + 1]);
            }
    
    delete[] characteristics;
}

int SumColumn(int** matrix, int num_rows, int column)
{
    int sum = 0;
    for (int i = 0; i < num_rows; i++)
        sum += matrix[i][column];
    return sum;
}

void PrintColumnsSums(int** matrix, int num_rows, int num_cols)
{
    cout << "\nSum of elements in columns with at least one negative element:\n";
    bool no_negatives = true;
    for (int j = 0; j < num_cols; j++)
        for (int i = 0; i < num_rows; i++)
            if (matrix[i][j] < 0)
            {
                cout << j + 1 << " column sum: ";
                cout << SumColumn(matrix, num_rows, j) << endl;
                no_negatives = false;
                break;
            }
    
    if (no_negatives)
        cout << "No columns with negative elements!\n";
}
