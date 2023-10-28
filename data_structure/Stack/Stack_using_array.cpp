#include<iostream>
using namespace std;


//stack implementation using array
class stack{
    public:

// structure od Stack u
    int *arr;
    int top;
    int size;

// constructure to initialize the values 
    stack(int size){
        top = -1;
        this->size= size;
        arr = new int[size];
    }

//stack methods

//push element 
void push(int val){

    //to check stack have space to insert element
    if(size - top > 1){
        top++;
        arr[top] = val;
    }
    else{
        cout<<"Stack Overflow"<<endl;
    }
}

// pop element
void pop(){
    //check if stack is not empty or have at least 1 element to delete 
    if(top>=0){
        top--;
    }
    else{
        cout<<"Stack Underflow"<<endl;
    }
}

//top element 
int Top(){
    //is stack not empty or have at least one element 
    if(top>=0){
        return arr[top];
    }
    else{
        cout<<"stack is empty"<<endl;
        return -1;
    }
}

// to check stack is empty or not 
bool isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

};

int main(){

   stack st(5);

   st.push(1);
   st.push(2);
   st.push(3);
   st.push(4);
   st.push(5);

   for(int i=0; i<5; i++){
      cout<<st.Top()<<" ";
        st.pop();
   }
   cout<<endl;

  
 
   cout<<st.Top()<<endl;


    return 0;
}