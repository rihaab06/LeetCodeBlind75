#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
    vector<vector<int>> threesum(vector<int>& nums){
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if(i>0 && nums[i] == nums[i-1]) continue;

            int left  = i+1;
            int right = nums.size()-1;

            while (left<right)
            {
                int sum = nums[i] + nums[left]+nums[right];
                if (sum == 0)
                {
                    result.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left] == nums[left+1]) left++;
                    while(left<right && nums[right] == nums[right-1]) left++;

                    left++;
                    right--;

                }
                else if(sum<0){
                        left++;
                }
                else{
                    right++;
                }
            }
            
        }
        
return result;
    }

};
int main(){
    Solution sol;
    vector<int> nums = {-1,0,1,2,-1,4};
    vector<vector<int>> result = sol.threesum(nums);
    for(auto triplet: result){
        cout<<"[";
        for (int x : triplet)
        {
            cout<<x<<" ";
        }
        cout<<"]\n";
        
    }
    
    
    cout<<endl;


return 0;
}