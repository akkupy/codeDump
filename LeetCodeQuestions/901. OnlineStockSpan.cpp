class StockSpanner {
public:
    stack<pair<int,int>> st;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        
        while(!st.empty() && st.top().first<=price)
        {
            auto x = st.top();
            st.pop();
            int first = x.first;
            int second = x.second;
            ans += second;
        }
        st.push({price,ans});
        return ans;
    }
};
