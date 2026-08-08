//DS used is heap and priority queue
//we should first sort the array to find the median easily
//        SMALLER HALF        LARGER HALF
    //    ┌───────────┐       ┌───────────┐
    //    │ Max Heap  │       │ Min Heap  │
    //    │           │       │           │
    //    │    5      │       │    8      │
    //    │  3   4    │       │  9   10   │
    //    └───────────┘       └───────────┘
    //          ↑                   ↑
    //       largest              smallest
    //       of small             of large
// left = max heap → largest element of smaller half
// right = min heap → smallest element of larger half
// Keep their sizes equal, or let left have exactly one extra.
// Therefore the median is always immediately available.
#include<iostream>
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;
class MedianFinder{
private:
    // small = smaller half (max heap = LARGEST NUMBER IN SMALLER HALF)
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;
public:
    MedianFinder(){}
    void addNum(int num){
          // Add to small first
        small.push(num);
        // Make sure small.top() <= large.top()
    if (!large.empty()&& small.top()>large.top())
        {
            large.push(small.top());
            small.pop();
            //"If the largest element of small is bigger than the smallest element of large, move that largest element from small to large.

        }
    //balance the sizes
    if (small.size()> large.size()+1)
    {
        large.push(small.top());
        small.pop();
    }
    if (large.size()>small.size())
    {
        small.push(large.top());
        large.pop();
    }
    
        

}
double findMedian(){
    //odd number of element
    if (small.size()>large.size())
    {
        return small.top();
    }
    //even number of elements
    return (small.top()+large.top())/2.0;
    
}
};
int main(){
    MedianFinder mf;

    mf.addNum(1);
    cout << mf.findMedian() << endl;

    mf.addNum(2);
    cout << mf.findMedian() << endl;

    mf.addNum(3);
    cout << mf.findMedian() << endl;

    mf.addNum(4);
    cout << mf.findMedian() << endl;

    mf.addNum(5);
    cout << mf.findMedian() << endl;

    return 0;
}