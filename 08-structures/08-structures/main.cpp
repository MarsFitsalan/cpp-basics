#include <iostream>
#include <string>
#include <iomanip>
#include <regex>

using namespace std;

struct Train
{
    string destination;
    int train_number;
    string departure_time;
};

bool IsTime(string time);
void AddTrains(Train trains[], const int kNumTrains);
void SortTrains(Train trains[], const int kNumTrains);
void PrintTrains(Train trains[], const int kNumTrains);
void FindTrains(Train trains[], const int kNumTrains, string find);

int main()
{
    const int kNumTrains = 6;
    Train trains[kNumTrains];
    
    AddTrains(trains, kNumTrains);
    
    cout << "\nTrains sorted by departure time:\n";
    SortTrains(trains, kNumTrains);
    PrintTrains(trains, kNumTrains);
    
    string find;
    cout << "\nEnter the destination for search -> ";
    cin >> find;
    FindTrains(trains, kNumTrains, find);
    
    return 0;
}

bool IsTime(string time)
{
    if (regex_match(time, regex("([0-1][0-9]|2[0-3]):[0-5][0-9]")))
        return 1;
    else
        return 0;
}

void AddTrains(Train trains[], const int kNumTrains)
{
    for (int i = 0; i < kNumTrains; i++)
    {
        cout << i + 1 << ". Train\n";
        cout << "Enter destination (e.g. New York) -> ";
        getline(cin, trains[i].destination);
        
        cout << "Enter train number (e.g. 11) -> ";
        cin >> trains[i].train_number;
        cin.ignore();
        
        while (true)
        {
            cout << "Enter departure time (hh:mm) -> ";
            getline(cin, trains[i].departure_time);
            if (IsTime(trains[i].departure_time))
                break;
            else
                cout << "Indalid time format!\n";
        }
        cout << endl;
    }
}

void SortTrains(Train trains[], const int kNumTrains)
{
    for (int i = 0; i < kNumTrains - 1; i++)
        for (int j = 0; j < kNumTrains - i - 1; j++)
            if (trains[j].departure_time > trains[j + 1].departure_time)
                swap(trains[j], trains[j + 1]);
}

void PrintTrains(Train trains[], const int kNumTrains)
{
    cout << string(44, '-') << endl;
    cout << "|" << setw(20) << "destination";
    cout << "|" << setw(10) << "number";
    cout << "|" << setw(10) << "time";
    cout << "|\n";
    cout << string(44, '-') << endl;
    
    for (int i = 0; i < kNumTrains; i++)
    {
        cout << "|" << setw(20) << trains[i].destination;
        cout << "|" << setw(10) << trains[i].train_number;
        cout << "|" << setw(10) << trains[i].departure_time;
        cout << "|\n";
    }
    cout << string(44, '-') << endl;
}

void FindTrains(Train trains[], const int kNumTrains, string find)
{
    bool found = false;
    for (int i = 0; i < kNumTrains; i++)
    {
        if (trains[i].destination == find)
        {
            found = true;
            cout << "|" << setw(20) << trains[i].destination;
            cout << "|" << setw(10) << trains[i].train_number;
            cout << "|" << setw(10) << trains[i].departure_time;
            cout << "|\n";
        }
    }
    
    if (!found)
        cout << "No trains were found!\n";
}
