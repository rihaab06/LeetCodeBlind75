#include <iostream>
#include <vector>
using namespace std;

class Solution {
public: // <- this is important
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // empty vector if no solution
    }
};

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target);

    cout << result[0] << ", " << result[1] << endl; // Output: 0, 1
}
