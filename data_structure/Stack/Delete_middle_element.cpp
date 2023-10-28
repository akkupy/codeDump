#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&inputStack, int count, int size){

   //base case
   if(count==size/2){
      inputStack.pop();
      return;
   }

   int num = inputStack.top();   //store the top element 
   inputStack.pop(); //pop that element

   //recursive call 
   solve(inputStack,count+1, size);  

   inputStack.push(num); // push back the top elements which pop in the process 
}


void deleteMiddle(stack<int>&inputStack, int N){
	
  int count =0;
  solve(inputStack,count,N);
   
}

int main(){

    stack<int> inputStack;

    inputStack.push(5);
     inputStack.push(9);
      inputStack.push(12);
       inputStack.push(8);
        inputStack.push(4);

    int N = inputStack.size();

    //  for(int i=0; i<N; i++){
    //     cout<<inputStack.top()<<" ";
    //     inputStack.pop();
    // }
    // cout<<endl;

    deleteMiddle(inputStack,N);

    for(int i=0; i<N; i++){
        cout<<inputStack.top()<<" ";
        inputStack.pop();
    }

    return 0;
}