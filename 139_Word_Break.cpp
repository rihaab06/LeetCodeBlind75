#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution{
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        vector<bool>dp(n+1,false);
        dp[0] = true;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && words.count(s.substr(j,i-j)))
                {
                    dp[i]=true;
                    break;
                }
                
            }
            
        }
      return dp[n];  
    }

};
int main(){
    Solution sol;

    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    cout << sol.wordBreak(s, wordDict);
return 0;
}