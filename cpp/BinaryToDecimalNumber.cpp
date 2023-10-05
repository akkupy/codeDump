#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the binary number : " << endl;
    int n;
    cin >> n;

    int ans = 0;
    int power = 1;
    while (n > 0)
    {
        int lastdigit = n % 10;
        ans += (lastdigit * power);
        power *= 2;
        n /= 10;
    }
    cout <<"The Decimal Number is " << ans << endl;

    return 0;
}
