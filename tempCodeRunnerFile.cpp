#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:


};
int main(){
    Solution sol;
    vector<int> nums = {-1,0,1,2,-1,4};
    sort(nums.begin(),nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;


return 0;
}