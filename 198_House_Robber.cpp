#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:    int rob(vector<int>& nums) {
        int s = nums.size();
        if (s == 1)
        {
            return nums[0];
        }
        vector<int> dp(s);
        dp[0] = nums[0];
        dp[1] = max(dp[0],nums[1]);
        for (int i = 2; i < s; i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[s-1];
    }

};
int main(){
     vector<int> nums = {2, 7, 9, 3, 1};

    Solution solution;

    int answer = solution.rob(nums);

    cout << "Maximum money robbed: " << answer << endl;

return 0;
}