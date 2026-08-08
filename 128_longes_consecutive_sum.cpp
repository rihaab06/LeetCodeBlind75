#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;
class Solution{
public:
  int longestConsecutive(vector<int>& nums) {
     unordered_set<int> numSet(nums.begin(),nums.end());
     int longest_streak = 0;
     for(int num:numSet){
        if (numSet.find(num-1)== numSet.end())
        {
            int current_num = num;
            int current_streak = 1;

            while (numSet.find(current_num+1)!= numSet.end())
            {
                 current_num++;
                 current_streak++;
            }
            longest_streak = max(longest_streak,current_streak);
        }
        
     }

     return longest_streak;   
    }

};
int main(){
    Solution sol;
    vector<int> nums = {10,4,200,1,3,2};
    int length = sol.longestConsecutive(nums);
    cout<<length<<endl;
return 0;
}