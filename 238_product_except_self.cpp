#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums){
            int n = nums.size();
        vector<int> answer(n, 1);
            int prefix = 1;
            int suffix = 1;
            for (int i = 0; i < n; i++)
            {
                answer[i]=prefix;
                prefix = prefix*nums[i];   
            }
            for (int i = n-1; i >= 0; i--)
            {
                answer[i] = answer[i]*suffix;
                suffix = suffix * nums[i];
            }

            return answer;   
    }
void printVector(vector<int> result){
     cout<<"[ ";
    for (int i = 0; i < result.size(); i++)
    {
       cout<<result[i];
        if (i != result.size() - 1) cout << ", ";
       }
    cout<<"]"<<endl;
    
}
};


int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4};
    vector<int> result = sol.productExceptSelf(nums);
    sol.printVector(result);
}