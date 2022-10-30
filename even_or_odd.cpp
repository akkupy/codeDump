#include<iostream>
using namespace std;

int main(){
    cout<<"Even or Odd teller"<<endl;

    int x;

    cout<<"Enter x : "<<endl;
    cin>>x;

    if(x%2 == 0)
    {
        
        cout<<"Even No.";
    }

    else
    {
        cout<<"Odd No.";
    }
    return 0;
}