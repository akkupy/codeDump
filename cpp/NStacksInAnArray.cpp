
// https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271?leftPanelTab=1

#include <bits/stdc++.h> 
class NStack
{
    int *arr;
    int *top;
    int *next;
    int freeSpace;
    
    int stackSize, arrSize;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        stackSize= N;
        arrSize= S;
        arr= new int[arrSize];
        top= new int[stackSize];
        next= new int[arrSize];
        
        for(int i=0; i<stackSize; i++)
            top[i]= -1;
        
        for(int i=0; i<arrSize; i++)
            next[i]= i+1;
        next[arrSize-1]= -1;
        freeSpace= 0;
        
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if(freeSpace == -1)
            return false;
        
        // Get free space
        int index= freeSpace;
        
        //Update freeSpace;
        freeSpace= next[index];
        
        //Store the Value
        arr[index]= x;
        
        //Update the next
        next[index]= top[m-1];
        
        //Update top of the stack
        top[m-1]= index;
        
        return true;
        
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if(top[m-1]==-1)
            return -1;
        
        //Get the top index
        int index= top[m-1];
        
        //Update top
        top[m-1]= next[index];
        
        //Update next
        next[index]= freeSpace;
        
        //Update freeSpace
        freeSpace= index;
        
        return arr[index];
        
    }
};





