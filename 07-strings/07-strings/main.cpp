#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string file_name = "/Users/marsfitsalan/Desktop/";
    file_name += "cpp-basics/07-strings/07-strings/text.txt";
    ifstream fin(file_name);
    if (!fin.is_open())
    {
        cout << "Can't open " << file_name << "!\n";
        return 1;
    }
    
    cout << "Quotes:\n";
    string s;
    bool end_quote = false;
    while (getline(fin, s, '"'))
    {
        if (end_quote)
        {
            cout << s << endl;
            end_quote = false;
        }
        else
        {
            end_quote = true;
        }
    }
    fin.close();
    return 0;
}
