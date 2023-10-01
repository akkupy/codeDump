
// https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int startRow= 0;
        int endRow= n-1;
        int startColumn= 0;
        int endColumn= n-1;
        int count = 1;
        n= n*n;

        while(count<n+1){

            for(int i=startColumn; i<=endColumn; i++){
                ans[startRow][i]= count;
                count++;
            }
            startRow++;

            if(count==n+1)
                break;

            for(int i=startRow; i<=endRow; i++){
                ans[i][endColumn]= count;
                count++;
            }
            endColumn--;

            if(count==n+1)
                break;

            for(int i=endColumn; i>=startColumn; i--){
                ans[endRow][i]= count;
                count++;
            }
            endRow--;

            if(count==n+1)
                break;

            for(int i=endRow; i>=startRow; i--){
                ans[i][startColumn]= count;
                count++;
            }
            startColumn++;

        }

        return ans;
    }
};