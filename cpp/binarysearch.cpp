#include <iostream>
using namespace std;

int main()
{
    int Arr[15] = {6,8,13,17,20,22,25,28,30,35}, low = 0 , high = 9 , mid , srch;
    cout << "Enter the Element to search : ";
    cin >> srch;

    while(low <= high)
    {
        mid = (low + high)/2;
        if(srch == Arr[mid])
        {
            cout << "Search successful." << endl;
            cout << "The Element is found at " << mid << endl;
            return 0;
        }
        else if(srch < Arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << "Search unsuccessful." << endl;
    cout << "Element not found." << endl;


}
