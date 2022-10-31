class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }

    void push(int val) {
        if(st.empty()){
            st.push({val,val});
            return ;
        }
        if(st.top().second<val){
            st.push({val,st.top().second});
            return ;
        }
        st.push({val,val});
    }
    
    void pop() {    
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};