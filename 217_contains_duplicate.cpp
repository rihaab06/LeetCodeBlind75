
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution{
    public:
    bool containsDuplicate(vector<int>& nums){
        unordered_set<int> seen;
        for (int n : nums)
        {
            if (seen.count(n))      
            {
                return true;
            }
            seen.insert(n);
        }
        return false;
        
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,1};
    bool result = sol.containsDuplicate(nums);
    if (result)
    {
        cout<<"TRUE";
    }else{
        cout<<"False";
    }
    
    return 0;
}