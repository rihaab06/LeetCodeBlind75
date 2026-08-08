#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int result = nums[0];

        while (left <= right) {
            // if subarray is sorted, left is min
            if (nums[left] < nums[right]) {
                result = min(result, nums[left]);
                break;
            }

            int mid = (left + right) / 2;
            result = min(result, nums[mid]);

            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,4,5,1,2};
    vector<int> nums2 = {4,5,6,7,0,1,2};
    vector<int> nums3 = {11,13,15,17};
    vector<int> numssorted = {1,2,3,4,5};

    int result = sol.findMin(numssorted);
    cout<<result<<endl;
return 0;
}