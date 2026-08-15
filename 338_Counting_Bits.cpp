#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
     vector<int> countBits(int n) {
    vector<int> ans(n+1,0);
    for (int i = 0; i <= n; i++)
    {
        ans[i] = ans[i>>1]+(i&1);
    }
     return ans;
    }
};
int main(){
    Solution sol;

    int n = 5;

    vector<int> result = sol.countBits(n);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
return 0;
}