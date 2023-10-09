class Solution {
public:
    void helper(int i,int n,int k,vector<int>subSet,vector<vector<int>>&ans){
        if(k==0){
            ans.push_back(subSet);
            return;
        }
        if(k>n-i+1){
            return;
        }
        // include
        subSet.push_back(i);
        helper(i+1,n,k-1,subSet,ans);

        // dont include
        subSet.pop_back();
        helper(i+1,n,k,subSet,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> subSet;
        helper(1,n,k,subSet,ans);
        return ans;    
    }
};