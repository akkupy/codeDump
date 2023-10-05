#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // Check if the input vector has fewer than 3 elements, as we need at least 3 for the pattern
        if (nums.size() < 3) {
            return false;
        }

        stack<int> st;
        int thirdElement = INT_MIN; // Initialize the third element to negative infinity

        // Iterate through the input vector from right to left
        for (int i = nums.size() - 1; i >= 0; i--) {
            int curr = nums[i]; // Current element

            // If we find a current element smaller than the third element, return true
            if (curr < thirdElement) {
                return true;
            }

            // Update the third element while the stack is not empty and its top element is smaller than the current element
            while (!st.empty() && st.top() < curr) {
                thirdElement = st.top(); // Update the third element
                st.pop(); // Pop elements from the stack
            }

            st.push(curr); // Push the current element onto the stack
        }

        return false; // If no pattern is found, return false
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4}; // Example input
    Solution solution;
    
    bool result = solution.find132pattern(nums);

    if (result) {
        cout << "The 132 pattern exists in the input vector." << endl;
    } else {
        cout << "No 132 pattern found in the input vector." << endl;
    }

    return 0;
}
