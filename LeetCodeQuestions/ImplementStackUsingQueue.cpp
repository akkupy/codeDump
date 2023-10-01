
// This is the solution for Implement Stack Using Queue question from Leetcode
// https://leetcode.com/problems/implement-stack-using-queues/description/

class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int size= q.size();
        q.push(x);
        while(size!=0){
            int temp= q.front();
            q.pop();
            q.push(temp);
            size--;
        }
    }
    
    int pop() {
        int val= q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};