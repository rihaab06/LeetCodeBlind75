#include<iostream>
#include<vector>


using namespace std;
class Solution{
public:
    pair<int, vector<int>> maxSubArray(vector<int> nums){
        int curr_sum = nums[0];
        int max_sum = nums[0];
        int start = 0,temp_start= 0,end = 0;
        for (int i = 1; i < nums.size( ); i++)
        {
            if (curr_sum+nums[i]<nums[i])
            {
                curr_sum = nums[i];
                temp_start = i;
                
            }else{
                curr_sum+=nums[i];
            }
            if (curr_sum>max_sum)
            {
                max_sum = curr_sum;
                start = temp_start;
                end = i;
            }
            
           
        }
            
            
            vector<int> subarray(nums.begin() + start , nums.begin()+end+1);
            return {max_sum,subarray};
       
        

    }

};
int main(){
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    auto result = sol.maxSubArray(nums); 
    cout<<"The maximum sum of the subarrays [";
    for (size_t i = 0; i < result.second.size(); i++) {
    cout << result.second[i];
    if (i != result.second.size() - 1) {
        cout << ",";  // print comma only if it's not the last element
    }
}
    cout<<"] ";
    cout<<"is "<<result.first<<endl;
return 0;
}