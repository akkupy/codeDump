
// https://leetcode.com/problems/russian-doll-envelopes/description/

bool comp(vector<int> a, vector<int> b){
        if(a[0]<b[0])
            return true;
        else if(a[0]>b[0])
            return false;
        else
            return a[1]>b[1];
}
class Solution {
public:
    int solve(vector<vector<int>> &envelopes){
        if(envelopes.size()==0)
            return 0;
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1; i<envelopes.size(); i++){
            if(envelopes[i][1]>ans.back()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                int index= lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                if(index==envelopes.size()){
                    ans.push_back(envelopes[i][1]);
                }else{
                    ans[index]= envelopes[i][1];
                }
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        return solve(envelopes);
    }
};