// Rectangle pattern in cpp
#include <iostream>
using namespace std;
int main()
{
    int length, bridth;
    cout << "Enter length : ";
    cin >> length;
    cout << "Enter bridth: ";
    cin >> bridth;
    for (int row = 0; row < bridth; row++)
    {
        for (int col = 0; col < length; col++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
}