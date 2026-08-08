#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
public:
    int subarraySum(vector<int>& nums,int k){
        unordered_map<int,int> prefixMap;
        prefixMap[0]=1;
        int prefixSum = 0;
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum+=nums[i];

            if (prefixMap.find(prefixSum-k)!=prefixMap.end())       
            {
                count += prefixMap[prefixSum-k];
            }
            prefixMap[prefixSum]++;
            
        }
        

    return count;
    }

};
int main(){
    Solution sol;
    vector<int> nums = {1,1,1};
    int k  = 2;
    int result = sol.subarraySum(nums,k);
    cout<<result;
return 0;
}