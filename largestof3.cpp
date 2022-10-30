#include <iostream>
using namespace std;

int main()
{
    cout << "Largest of 3 numbers" << endl;
    int x, y, z;
    cout << "Enter 3 nummbers=" << endl;
    cin >> x >> y >> z;

    if (x > y)
    {
        if (x > z)
        {
            cout << x << "X is the greatest number" << endl;
        }

        else
        {
            cout << z << "Z is the greatest number  " << endl;
        }
    }
    else if (y > x)
    {
        if (y > z)
        {
            cout << y << "Y is the greatest number";
        }
        else
        {
            cout << z << "is the greatest number" << endl;
        }
    }
    return 0;
}