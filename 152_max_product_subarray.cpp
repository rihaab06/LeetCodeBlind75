#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int maxProduct(vector<int> nums){
        int max_product = nums[0];
        int min_product = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int curr = nums[i];

            int tempMax= max_product;

            max_product = max(curr, max(curr*max_product, curr*min_product));
            min_product = min(curr, min(curr*tempMax, curr*min_product));       
            ans = max(ans,max_product);
            
            }
            return ans;
        
    }
};
int main(){
    Solution sol;
    vector<int> nums = {2,3,-4,2};
    int result = sol.maxProduct(nums);
    cout<<"The maximum product of the subarray: "<<result<<endl;
return 0;
}