// This is the solution for Revserse Integer question from Leetcode
//https://leetcode.com/problems/reverse-integer/submissions/

class Solution {
public:
    int reverse(int x) {
        int rv=0;
        while(x!=0){
            if(rv>(INT_MAX/10) || rv<(INT_MIN/10)){
                return 0;
            }
            rv=rv*10+x%10;
            x=x/10;
        }
        return rv;
    }
};
