/*
  This code solves the 48th problem of leetcode "Rotate Image"
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i!=j){
                    int temp=matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=temp;
                }
            }
        }
        for(int i=0;i<(n/2);i++){
            for(int j=0;j<n;j++){
                int temp=matrix[j][i];
                matrix[j][i]=matrix[j][n-i-1];
                matrix[j][n-i-1]=temp;
            }
        }
    }
};
