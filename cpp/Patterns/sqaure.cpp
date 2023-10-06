// Printing sqaure pattern in cpp
#include <iostream>
using namespace std;
int main(){
    int n=4;
    cout <<"Enter size: ";
    cin >> n;
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
                cout<<"* ";
        }
        cout << endl;
    }
    return 0;
}