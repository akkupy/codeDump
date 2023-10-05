
//https://leetcode.com/problems/spiral-matrix/

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
            int m= matrix.size();
            int n= matrix[0].size();
            int startRow= 0, endRow= m;
            int startColumn= 0, endColumn= n;
            vector<int> ans(m*n);
            int count=0;
    
            while(count!=m*n){
    
                for(int i=startColumn; i<endColumn; i++){
                    ans[count]=(matrix[startRow][i]);
                    count++;
                }
                startRow++;
    
                if(count==(m*n))
                    break;
    
                for(int i=startRow; i<endRow; i++){
                    ans[count]=(matrix[i][endColumn-1]);
                    count++;
                }
                endColumn--;
    
                if(count==(m*n))
                    break;
    
                for(int i=endColumn-1; i>=startColumn; i--){
                    ans[count]=(matrix[endRow-1][i]);
                    count++;
                }
                endRow--;
    
                if(count==(m*n))
                    break;
    
                for(int i=endRow-1; i>=startRow; i--){
                    ans[count]=(matrix[i][startColumn]);
                    count++;
                }
                startColumn++;
    
            }
    
            return ans;
    
        }
    };