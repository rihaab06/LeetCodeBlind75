#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;      
class Solution{
public:
    int robRange(vector<int> nums,int start,int end){
        if (start ==end)
        {
            return nums[start];
        }
        
        int prev2 = nums[start];
        int prev1 = max(nums[start],nums[start+1]);
        for (int i = start+2; i <=end; i++)
        {
            int current = max(prev1,prev2+nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1)
        {
            return nums[0];
        }
        int case1 = robRange(nums,0,n-2);
        int case2 = robRange(nums,1,n-1);
        return max(case1,case2);
        
    }
};
int main(){
    vector<int> nums = {2, 3, 2};

    Solution solution;

    int answer = solution.rob(nums);

    cout << "Maximum money robbed: " << answer << endl;

    return 0;
return 0;
}