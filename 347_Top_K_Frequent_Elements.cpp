#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int n: nums)freq[n]++;  //it is take the key value of of n add 1 to it
           // Min-heap of pairs {frequency, number}
           priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
            // pair<int, int>	Each element in heap is a pair: {frequency, number}
            // vector<pair<int, int>>	The heap is internally stored as a vector (like an array)
            // reater<pair<int, int>>	This makes it a min-heap instead of default max-heap
            for(auto& [num,count]:freq){
                minHeap.push({count,num});
                if(minHeap.size()>k) minHeap.pop();
            }
            vector<int> res;
            while (!minHeap.empty())
            {
                res.push_back(minHeap.top().second);
                minHeap.pop();

            }
            return res;
    }

};
int main(){
     Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> ans = s.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

   
return 0;
}