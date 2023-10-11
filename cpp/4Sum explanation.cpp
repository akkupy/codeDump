// Problem Statement: Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.
// Note:
// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// arr[a] + arr[b] + arr[c] + arr[d] == target

// Naive Approach (Brute-force): 
// Approach:
// The steps are as follows:
// 1. First, we will declare a set data structure as we want unique quadruplets.
// 2. Then we will use the first loop(say i) that will run from 0 to n-1.
// 3. Inside it, there will be the second loop(say j) that will run from i+1 to n-1.
// 4. Then there will be the third loop(say k) that runs from j+1 to n-1.
// 5. Inside loop k, the fourth loop(say l) will run from k+1 to n-1.
// 6. Now, inside these four nested loops, we will check the sum i.e. arr[i]+arr[j]+arr[k]+arr[l], and if it is equal to the target we will sort this quadruplet and insert it in the set data structure.
// // 7. Finally, we will return a list of stored quadruplets.
// Time Complexity: O(N4), where N = size of the array.
// Reason: Here, we are mainly using 4 nested loops. But we not considering the time complexity of sorting as we are just sorting 4 elements every time.

// Space Complexity: O(2 * no. of the quadruplets) as we are using a set data structure and a list to store the quads.
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    // taking bigger data type
                    // to avoid integer overflow:
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}


// Optimal Approach: 
// Approach:
// The steps are as follows:
// 1. First, we will sort the entire array.
// 2. We will use a loop(say i) that will run from 0 to n-1. This i will represent one of the fixed pointers. In each iteration, this value will be fixed for all different values of the rest of the 3 pointers. Inside the loop, we will first check if the current and the previous element is the same and if it is we will do nothing and continue to the next value of i.
// 3. After checking inside the loop, we will introduce another fixed pointer j(runs from i+1 to n-1) using another loop. Inside this second loop, we will again check for duplicate elements and only perform any further operation if the elements are different.
// 4. Inside the second loop, there will be 2 moving pointers i.e. k(starts from j+1) and l(starts from the last index). The pointer k will move forward and the pointer l will move backward until they cross each other while the value of i and j will be fixed.
// 5. Now we will check the sum i.e. nums[i]+nums[j]+nums[k]+nums[l].
// 6. If the sum is greater, then we need lesser elements and so we will decrease the value of l.
// 7. If the sum is lesser than the target, we need a bigger value and so we will increase the value of k. 
// 8. If the sum is equal to the target, we will simply insert the quad i.e. nums[i], nums[j], nums[k], and nums[l] into our answer and move the pointers k and l skipping the duplicate elements(i.e. by checking the adjacent elements while moving the pointers).
// 9. Finally, we will have a list of unique quadruplets.

// Time Complexity: O(N3), where N = size of the array.
// Reason: Each of the pointers i and j, is running for approximately N times. And both the pointers k and l combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N3). 
// Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).




#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}


