#include<iostream>
using namespace std;

class node{
    public:

    int data;
    node* next;

    node(int val){
        this->data = val;
        this->next = NULL;
    }
};

//top pointer to track the top element of the stack 
node *top = NULL;

//function to check if stack is empty or not 
bool isEmpty(){

    if(top==NULL){
        return true;
    }
    else{
        return false;
    }
}

//function to insert elemnet in the stack 
void push(int val){
    node* newnode = new node(val);
    newnode->data = val;
    newnode->next = top;
    top=newnode;
}

//function to delete / pop element from the stack
void pop(){
    if(isEmpty()){
        cout<<"nothing to delete allready  empty"<<endl;
    }
    else{
        node* temp = top;
        top=top->next;
        delete temp;
    }
}

//function to display the top element 
void Top(){
    if(isEmpty()){
        cout<<"empty stack nothing to show"<<endl;
    }
    else{
        cout<<"top element is "<<top->data<<endl;
    }
}

//function to print the value of the stack 
void display(){
    if(isEmpty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        node* temp = top;

        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

int main(){

    push(1);
    push(2);
    push(3);

    display();
    pop();
    display();
    Top();
  cout<< isEmpty();


    return 0;
}