#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
class Solution{
public:
int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0;
        int max_length = 0;

        for (int right = 0; right < s.length(); right++)
        {
            while (seen.count(s[right]))
            {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            int current_length = right-left+1;
            max_length = max(current_length,max_length);
        }
        return max_length;
    }

};
int main(){
    Solution sol;
    string s= "abcabcdebbb";
    int length = sol.lengthOfLongestSubstring(s);
    cout<<"The maximum length of the unique substring is: "<<length<<endl;
return 0;
}