
// This is the solution for Implement Queue Using Stack question from Leetcode
// https://leetcode.com/problems/implement-queue-using-stacks/description/

class MyQueue {
    stack<int> st;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        insertAtBottom(st, x);
    }

    void insertAtBottom(stack<int> &st, int &val){
        if(st.empty()){
            st.push(val);
            return;
        }

        int temp= st.top();
        st.pop();
        insertAtBottom(st, val);
        st.push(temp);
    }
    
    int pop() {
        int val= st.top();
        st.pop();
        return val;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};