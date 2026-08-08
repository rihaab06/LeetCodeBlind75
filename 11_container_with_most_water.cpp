#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int maxArea(vector<int>& heights){
        int left = 0;
        int right = heights.size()-1;
        int maxArea = 0;


        while (left<right)
        {
            int height = min(heights[left],heights[right]);
            int width = right-left;
            maxArea = max(maxArea, height*width);

            if (heights[left]<heights[right])
            {
                left++;
            }else{
                right--;
            }
            

        }
            return maxArea;
    }
};
int main(){
    Solution sol;
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    int maxAmount = sol.maxArea(heights);
    cout<<"The maximum amout of water the container store is "<<maxAmount<<endl;
return 0;
}