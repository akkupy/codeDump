
// https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?leftPanelTab=1

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);
        ans[n-1]=-1;
        for(int i=n-1;i>=0;i--){
            if(s.top()<arr[i]){
                ans[i] = s.top();
                s.push(arr[i]);
            }
            else{
                while(arr[i]<=s.top()){
                    s.pop();
                }
                ans[i]=s.top();
                s.push(arr[i]);
            }
        }
        return ans;
        
    } 
};