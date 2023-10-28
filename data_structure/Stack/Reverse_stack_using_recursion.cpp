#include<iostream>
#include<stack>
using namespace std;



void insertAtBottom(stack<int> &stack, int x){
    if(stack.empty()){
        stack.push(x);
        return;
    }

    int num = stack.top();
    stack.pop();

    insertAtBottom(stack, x);

    stack.push(num);
}

void reverseStack(stack<int> &stack) {
    
    //base case
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack,num);
}

int main(){

    stack<int> inputStack;

    inputStack.push(5);
     inputStack.push(9);
      inputStack.push(12);
       inputStack.push(8);
        inputStack.push(4);

//          for(int i=0; i<5; i++){
//     cout<<inputStack.top()<<" ";
//     inputStack.pop();
//  }

 reverseStack(inputStack);

 for(int i=0; i<5; i++){
    cout<<inputStack.top()<<" ";
    inputStack.pop();
 }


return 0;

}