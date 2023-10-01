
// This is the solution for Min Stack question from Leetcode
// https://leetcode.com/problems/min-stack/description/

class MinStack {
    stack<long> st;
    int minElement= INT_MAX;
public:
    MinStack() {}
    
    void push(int val) {
        if(val< minElement){
            st.push(2ll*val - minElement);
            minElement= val;
        }else{
            st.push(val);
        }
    }
    
    void pop() {

        if(st.empty())
            return;

        if(st.top()<minElement){
            minElement= 2ll*minElement - st.top(); 
        }            
        st.pop();

    }
    
    int top() {
        if(st.top()<minElement){
            return minElement;
        }
        return st.top();
    }
    
    int getMin() {
        return minElement;
    }
};
