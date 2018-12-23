#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

template <class T>
T** ReadMatrix(string file_name, int num_rows, int num_cols);

template <class T>
void PrintMatrix(T** matrix, int num_rows, int num_cols);

template <class T>
T* ComputeCharacteristics(T** matrix, int num_rows, int num_cols);

template <class T>
void SortMatrix(T** matrix, int num_rows, int num_cols);

template <class T>
T SumColumn(T** matrix, int num_rows, int column);

template <class T>
void PrintColumnsSums(T** matrix, int num_cols, int num_rows);

template <class T>
int Execute(string file_name);

int main()
{
    string select;
selection:
    cout << "Select the data type (0-integer, 1-double, 2-float): ";
    cin >> select;
    if (select == "0")
    {
        Execute<int>("int.txt");
    }
    else if (select == "1")
    {
        Execute<double>("double.txt");
    }
    else if (select == "2")
    {
        Execute<float>("float.txt");
    }
    else
    {
        cout << "Error input! (Only 0, 1 or 2).\n\n";
        goto selection;
    }
    
    return 0;
}

template <class T>
int Execute(string file_name)
{
    int num_rows = 3;
    int num_cols = 4;
    
    T** matrix = ReadMatrix<T>(file_name, num_rows, num_cols);
    if (!matrix) return 1;
    
    cout << "\nInitial matrix:\n";
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

template <class T>
T** ReadMatrix(string file_name, int num_rows, int num_cols)
{
    string path = "/Users/marsfitsalan/Desktop/";
    path += "cpp-basics/10-templates/10-templates/";
    ifstream fin(path + file_name);
    if (!fin.is_open())
    {
        cout << "\nCan't open file " << path + file_name << "!\n";
        return nullptr;
    }
    
    T** matrix = new T*[num_rows];
    for (int i = 0; i < num_rows; i++)
    {
        matrix[i] = new T[num_cols];
        for (int j = 0; j < num_cols; j++)
            fin >> matrix[i][j];
    }
    fin.close();
    return matrix;
}

template <class T>
void PrintMatrix(T** matrix, int num_rows, int num_cols)
{
    cout << string(5 * num_cols + 1, '-');
    for (int i = 0; i < num_rows; i++)
    {
        cout << "\n|";
        for (int j = 0; j < num_cols; j++)
            cout << setw(3) << matrix[i][j] << setw(2) << "|";
    }
    cout << endl << string(5 * num_cols + 1, '-');
    
    T* characteristics = ComputeCharacteristics(matrix, num_rows, num_cols);
    cout << "\n|";
    for (int j = 0; j < num_cols; j++)
        cout << setw(3) << characteristics[j] << setw(2) << "|";
    cout << endl << string(5 * num_cols + 1, '-');
    delete[] characteristics;
}

template <class T>
T* ComputeCharacteristics(T** matrix, int num_rows, int num_cols)
{
    T* characteristics = new T[num_cols];
    for (int j = 0; j < num_cols; j++)
    {
        characteristics[j] = 0;
        for (int i = 0; i < num_rows; i++)
            if ((matrix[i][j] < 0) && (static_cast<int>(matrix[i][j]) % 2 != 0))
                characteristics[j] += abs(matrix[i][j]);
    }
    return characteristics;
}

template <class T>
void SortMatrix(T** matrix, int num_rows, int num_cols)
{
    T* characteristics = ComputeCharacteristics(matrix, num_rows, num_cols);
    
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

template <class T>
T SumColumn(T** matrix, int num_rows, int column)
{
    T sum = 0;
    for (int i = 0; i < num_rows; i++)
        sum += matrix[i][column];
    return sum;
}

template <class T>
void PrintColumnsSums(T** matrix, int num_rows, int num_cols)
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
