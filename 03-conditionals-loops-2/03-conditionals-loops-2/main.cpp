#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    const int kMaxIters = 1000;
    
    double xn, xk, dx, eps;
    cout << "Please, enter xn > 1: ";
    cin >> xn;
    cout << "Please, enter xk >= xn: ";
    cin >> xk;
    cout << "Please, enter dx > 0: ";
    cin >> dx;
    cout << "Please, enter eps > 0: ";
    cin >> eps;
    
    if (xn > 1 && xk >= xn && dx > 0 && eps > 0)
    {
        cout << string(68, '-') << endl;
        cout << "|" << setw(7) << "x" << setw(7);
        cout << "|" << setw(19) << " arctg(x) (mine) ";
        cout << "|" << setw(19) << "arctg(x) (cmath) ";
        cout << "|" << setw(11) << "iterations" << setw(3) << "|\n";
        cout << string(68, '-') << endl;
        
        cout << fixed;
        
        for (double x = xn; x <= xk; x += dx)
        {
            int n;
            double arctg = M_PI_2, nth_term;
            for (n = 0; n <= kMaxIters; n++)
            {
                nth_term = pow(-1, n + 1) / ((2 * n + 1)*pow(x, 2 * n + 1));
                arctg += nth_term;
                if (abs(nth_term) < eps) break;
            }
            
            cout << "|" << setw(11) << x << setw(3) << "|";
            if (n <= kMaxIters)
                cout << setw(14) << arctg << setw(6);
            else
                cout << " limit is exceeded ";
            cout << "|" << setw(14) << atan(x) << setw(6);
            cout << "|" << setw(7) << n << setw(7) << "|\n";
        }
        cout << string(68, '-');
    }
    else
    {
        cout << "\nError: invalid values.\n";
    }
    
    return 0;
}
