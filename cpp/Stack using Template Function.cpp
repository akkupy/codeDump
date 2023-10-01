#include <iostream>
#include <vector>
#define MAX 5
using namespace std;

template <class type>

class STACK{
    private:
    type stack[MAX];
    int top = -1;
    public:
    void push(type);
    void pop();
    void display();
    void peek();
};

int main(){

    int choice;
    STACK<int> i;
    STACK<float> f;
    STACK<char> c;
    
    cout << "For integer : " << endl;
    i.push(1);
    i.push(3);
    i.push(5);
    i.display();
    i.pop();
    i.display();
    i.peek();

    cout << endl << "For float : " << endl;
    f.push(1.5);
    f.push(3.66);
    f.push(5.23);
    f.display();
    f.pop();
    f.display();
    f.peek();

    cout << endl << "For char : " << endl;
    c.push('a');
    c.push('c');
    c.push('e');
    c.display();
    c.pop();
    c.display();
    c.peek();

    return 0;
}

// Function Definitions

template <class type>
void STACK<type> :: push(type data){
        top ++;
        stack[top] = data;
}

template <class type>
void STACK<type> :: pop(){
    if(top == -1){
        cout << "Stack is Empty" << endl;
    }
    else{
        cout << "The Deleted Element is : " << stack[top] << endl;
        top --;
    }
}

template <class type>
void STACK<type> :: display(){
    if(top == -1){
        cout << "Stack is Empty" << endl;
    }
    else{
        printf("The Stack is : ");
        for(int i = top; i >= 0; i --){
            cout << stack[i];
            if(i != 0){
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

template <class type>
void STACK<type> :: peek(){
    if(top == -1){
        cout << "Stack is Empty" << endl;
    }
    else{
        cout << "The Top Element is : " << stack[top] << endl;
    }
}