
// Write a program to perform the arithmetic operations.
// #include<iostream>



/*
using namespace std;

int main(){
    int a; 
    int b;
    int sum,pro,div,sub;
    cout<<"Enter a : ";
    cin>>a;
    cout<<"Enter b : ";
    cin>>b;
    cout<<" ";
sum = a+b;
div = a/b;
sub = a-b;
pro = a*b;


cout<<"The sum of "<<a<<" and "<<b<<" is " <<sum<<endl;
cout<<"The Subtraction of "<<a<<" and "<<b<<" is "<<sub<<endl;
cout<<"The product of "<<a<<" and "<<b<<" is "<<pro<<endl;
cout<<"The division of "<<a<<" and "<<b<<" is "<<div<<endl;
    return 0;
}
*/


#include<iostream>
using namespace std;

int main(){
    cout<<"Arithmetic operations Program:";
    cout<<"Enter the option no. to continue with operation"<<endl;

    cout<<"1."<<endl<<"2."<<endl<<"3."<<endl<<"4."<<endl;

    int option_No;
    cin>>option_No;

    int x,y;

    switch(option_No)
    {
        case 1:

        cout<<"ADDITION OPERATIONS"<<"ENTER TWO NO.S";
        cin>>x>>y; //Two no.s for input

        cout<<"The Addition of" <<x<<"and" <<y<<"is"<<(x+y);

        break;



        case 2:

        cout<<"SUBSTRACTION OPERATIONS"<<"ENTER TWO NO.S";
        cin>>x>>y; //Two no.s for input

        cout<<"The Substraction of" <<x<<"and" <<y<<"is"<<(x-y);

        break;

        case3:

        cout<<"MULTIPLICATION OPERATIONS"<<"ENTER TWO NO.S";
        cin>>x>>y; //Two no.s for input

        cout<<"The Multiplication of" <<x<<"and" <<y<<"is"<<(x*y);

        break;

        

        case 4:

        cout<<"DIVISION OPERATIONS"<<"ENTER TWO NO.S";
        cin>>x>>y; //Two no.s for input
        cout<<"The Division of" <<x<<"and" <<y<<"is"<<(x/y);


        break;

        default:

        cout<<"ARTHMETIC OPERATION"<<"ENTER TWO NO.S";
        cin>>x>>y; //Two no.s for input

        cout<<"Invalid Input";

        break;


    }


    return 0;
}


