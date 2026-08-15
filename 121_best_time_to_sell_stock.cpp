#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r =1;
        int maxprofit = 0;
        while (r<prices.size())
        {
            if (prices[r]>prices[l])
            {
                int profit = prices[r]-prices[l];
                maxprofit = max(maxprofit,profit);
            }
            else{
                l=r;
            }
            r++;
        }
     return maxprofit;   
    }
};
int main(){
    
return 0;
}