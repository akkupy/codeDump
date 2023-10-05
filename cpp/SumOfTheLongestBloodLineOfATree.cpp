
// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

class Solution
{
public:
    void maximumSum(Node* root, int currSum, int &maxSum, int currLevel, int &longestLevel){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL){
            currSum+= root->data;
            if(currLevel>longestLevel){
                longestLevel= currLevel;
                maxSum= currSum;
            }
            else if(currLevel==longestLevel){
                if(currSum>maxSum)
                    maxSum=currSum;
            }
            return;
        }
        
        currSum += root->data;
        currLevel++;
            
        maximumSum(root->left, currSum, maxSum, currLevel, longestLevel);
        maximumSum(root->right, currSum, maxSum, currLevel, longestLevel);
        
        
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int maxSum= 0;
        int longestLevel= 0;
        maximumSum(root, 0, maxSum, 0, longestLevel);
        
        return maxSum;
    }
};