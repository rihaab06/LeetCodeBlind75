#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:

        vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return  {{}};
        int first = nums[0];
        vector<int> rest(nums.begin()+1,nums.end());
        vector<vector<int>> result;
        
        vector<vector<int>> perms = permute(rest);
        for(auto& perm: perms){
            for (int i = 0; i <= perm.size(); i++)
            {
                vector<int> temp = perm;
                temp.insert(temp.begin()+i,first);
                result.push_back(temp);
            }
            
        }
        return result;
    }

};
int main(){
    Solution sol;
    vector<int> nums = {1,2,3};

    vector<vector<int>> result = sol.permute(nums);

    for (auto& res : result) {
        cout << "[ ";
        for (int x : res) {
            cout << x << " ";
        }
        cout << "]\n";
    }




return 0;
}