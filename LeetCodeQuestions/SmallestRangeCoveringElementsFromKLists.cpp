
// This is the solution for Smallest Range Covering Elements From K Lists question from Leetcode
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

class Solution {
public:
    class Node{
        public:
            int data;
            int row;
            int col;
            int maxCol;
            Node(int data, int row, int col, int maxCol){
                this->data= data;
                this->row= row;
                this->col= col;
                this->maxCol= maxCol;
            }
    };
    class compare{
        public:
            bool operator()(Node* node1, Node* node2){
                return node1->data>node2->data;
            }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maxi= INT_MIN, mini= INT_MAX;
        priority_queue<Node*, vector<Node*>, compare> minHeap;

        for(int i=0; i<nums.size(); i++){
            maxi= max(maxi, nums[i][0]);
            mini= min(mini, nums[i][0]);
            minHeap.push(new Node(nums[i][0], i, 0, nums[i].size()));
        }

        int startAns= mini, endAns= maxi;

        while(!minHeap.empty()){
            Node* top= minHeap.top();
            minHeap.pop();

            mini= top->data;

            if(maxi-mini < endAns-startAns){
                startAns= mini;
                endAns= maxi;
            }

            if(top->col + 1 <top->maxCol){
                maxi= max(maxi, nums[top->row][top->col + 1]);
                minHeap.push(new Node(nums[top->row][top->col + 1], top->row, top->col+1, top->maxCol));
            }else{
                break;
            }

        }
        vector<int> ans;
        ans.push_back(startAns);
        ans.push_back(endAns);
        return ans;
    }
};










