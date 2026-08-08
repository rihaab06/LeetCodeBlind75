#include<iostream>
using namespace std;
class Solution{
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;  // base case
        int one = 1,two = 1;
        for (int  i = 2; i <= n; i++)
        {
            int temp = one;
            one = one+two;
            two = temp;

        }

        return one;
        
        
    }


};
int main(){
    Solution sol;
    cout<<sol.climbStairs(5)<<endl;
    cout<<sol.climbStairs(7)<<endl;
    cout<<sol.climbStairs(8)<<endl;
return 0;
}