
// https://leetcode.com/problems/longest-palindromic-subsequence/description/

class Solution {
public:
    int solve(string& s, string& p){
        vector<int> curr(s.length()+1, 0);
        vector<int> next(s.length()+1, 0);

        for(int i= s.length()-1; i>=0; i--){
            for(int j= p.length()-1; j>=0; j--){
                int ans=0;
                if(s[i]==p[j]){
                    ans= 1+next[j+1];
                }
                else{
                    ans= max(curr[j+1], next[j]);
                }
                curr[j]= ans;
            }
            next= curr;
        }
        return curr[0];
    }
    int longestPalindromeSubseq(string s) {
        string revStr= s;
        reverse(revStr.begin(), revStr.end());
        return solve(s, revStr);
    }
};