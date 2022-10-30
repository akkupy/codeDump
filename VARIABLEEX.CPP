#include<iostream>
using namespace std;

int main()
{
             //[datatype] variable name;


    int x, y ;   // variable declaration
    cout<<"Enter x   "<<endl;
    cin>>x;
    cout<<"Enter y   "<<endl;
    cin>>y;
    bool z;
    cout<< "The value of x is: "<<x<<"  "<<endl;
    cout<< "The value of y is: "<<y<<"  "<<endl;
    z = x > y;
    cout<<"The answer is : "<<z;


    return 0;
}