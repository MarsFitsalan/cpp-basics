#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    const double kEps = 1e-15;
    
    double a, b, c, xn, xk, dx;
    cout << "Enter a ";
    cin >> a;
    cout << "Enter b ";
    cin >> b;
    cout << "Enter c ";
    cin >> c;
    cout << "Enter xn ";
    cin >> xn;
    cout << "Enter xk (xk >= xn) ";
    cin >> xk;
    cout << "Enter dx (dx > 0) ";
    cin >> dx;
    
    if (dx > 0 && xn <= xk)
    {
        cout << endl << string(38, '-') << endl;
        cout << "|" << setw(9) << "x" << setw(9);
        cout << "|" << setw(10) << "F" << setw(9) << "|";
        cout << endl << string(38, '-') << endl;
        
        cout << fixed;
        cout.precision(3);
        
        double f;
        while (xn <= xk)
        {
            cout << "|" << setw(11) << xn << setw(7) << "|";
            if ((c < 0) && (abs(a) > kEps))
            {
                f = -a * pow(xn, 2);
            }
            else
            {
                if ((c > 0) && (abs(a) < kEps))
                {
                    if (abs(c * xn) > kEps)
                    {
                        f = (a - xn) / (c * xn);
                    }
                    else
                    {
                        cout << " division by zero |\n";
                        xn += dx;
                        continue;
                    }
                }
                else
                {
                    if (abs(c) > kEps)
                    {
                        f = xn / c;
                    }
                    else
                    {
                        cout << " division by zero |\n";
                        xn += dx;
                        continue;
                    }
                }
            }
            
            int ac = static_cast<int>(a);
            int bc = static_cast<int>(b);
            int cc = static_cast<int>(c);
            
            if ((ac ^ bc) & !(ac | cc))
                cout << setw(12) << f << setw(8);
            else
                cout << setw(10) << static_cast<int>(f) << setw(10);
            
            cout << "|\n";
            xn += dx;
        }
        cout << string(38, '-') << endl;
    }
    else
    {
        cout << "\nError input values.\n";
    }
    
    return 0;
}
