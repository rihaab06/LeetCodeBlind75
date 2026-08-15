#include<iostream>
using namespace std;
class Solution{
public:
int hammingWeight(int n) {
     int count = 0;
     while (n!=0)
     {
        n = n&(n-1);
        count++;
     }
        return count;
    }

};
int main(){
  Solution sol;

    int n = 11;  // 1011

    cout << sol.hammingWeight(n) << endl;

    return 0;
return 0;
}