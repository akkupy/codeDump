#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find two numbers that add up to a target sum
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> Nums; // Store number-index pairs
    vector<int> result;                  // Store the result indices

    // Iterate through the input vector
    for (int i = 0; i < nums.size(); ++i)
    {
        int  diff = target - nums[i]; // Calculate the  diff
        if (Nums.find( diff) != Nums.end())
        {
            // If  diff exists in the map, we found a solution
            result.push_back(Nums[ diff]);
            result.push_back(i);
            break; // Exit the loop
        }
        Nums[nums[i]] = i; // Store the current number and its index
    }

    return result;
}

int main()
{
    vector<int> nums = {5,4,5,8,6,8,9,2,4,6,8,9,2,4,};
    int target = 18;

    vector<int> result = twoSum(nums, target);

    if (result.size() == 2)
    {
        cout << "Indices of the two numbers that add up to " << target << ": " << result[0] << " and " << result[1] << endl;
    }
    else
    {
        cout << "No solution found." << endl;
    }

    return 0;
}
