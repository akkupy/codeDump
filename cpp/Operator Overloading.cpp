#include<iostream>
using namespace std;

class FLOAT{
    public:
    float value = 3;

    public:

    FLOAT(){}
    FLOAT(float val){
        value = val;
    }

    FLOAT operator + (FLOAT& other){
        FLOAT result;
        result.value = value + other.value;
        return result;
    }

    FLOAT operator - (FLOAT& other){
        FLOAT result;
        result.value = value - other.value;
        return result;
    }

    FLOAT operator * (FLOAT& other){
        FLOAT result;
        result.value = value * other.value;
        return result;
    }

    FLOAT operator / (FLOAT& other){
        FLOAT result;
        result.value = value / other.value;
        return result;
    }

    void display(){
        cout << value << endl;
    }

};

int main(){

    FLOAT num1(4), num2(2.3);
    cout << "num1 = ";
    num1.display();
    cout << "num2 = ";
    num2.display();
    cout << "num1 + num2 = ";
    (num1 + num2).display(); 
    cout << "num1 - num2 = ";
    (num1 - num2).display();
    cout << "num1 * num2 = ";
    (num1 * num2).display();
    cout << "num1 / num2 = ";
    (num1 / num2).display();

    return 0;
}