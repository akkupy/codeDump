#include<iostream>
#include<stack>
using namespace std;

void sort(stack<int> &stack, int x){

	//base case
	if(stack.empty() || !stack.empty() && stack.top() < x ){
		stack.push(x);
		return;
	}

	int n = stack.top();
	stack.pop();

	sort(stack,x);

	stack.push(n);

}

void sortStack(stack<int> &stack)
{
	//base case
	if(stack.empty()){
		return;
	}

	int num = stack.top();
	stack.pop();
    
	sortStack(stack);

	sort(stack,num);

}


int main(){

    stack<int> inputStack;

    inputStack.push(5);
     inputStack.push(9);
      inputStack.push(12);
       inputStack.push(8);
        inputStack.push(4);

        sortStack(inputStack);

         for(int i=0; i<5; i++){
    cout<<inputStack.top()<<" ";
    inputStack.pop();
 }


        return 0;

}