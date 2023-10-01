
// This is the solution for Minimum Add to Make Parenthesis Valid question from Leetcode
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            char t= st.top();
            if(t=='(' && s[i]==')')
                st.pop();
            else
                st.push(s[i]);
        }
        return st.size();
    }
};