#include <vector>
#include <iostream>
#include <queue>
using namespace std;
//Find Median from Data Stream
//https://leetcode.com/problems/find-median-from-data-stream/
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;

    MedianFinder() { }
    
    void addNum(int num) {
        smallHeap.push(num);

        if(!largeHeap.empty() && smallHeap.top() > largeHeap.top()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(smallHeap.size() > largeHeap.size() + 1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(largeHeap.size() > smallHeap.size() + 1){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();   
        }
    }
    
    double findMedian() {
        if(smallHeap.size() == largeHeap.size()){
            return (smallHeap.top() + largeHeap.top())/2.0;
        }else if (smallHeap.size() > largeHeap.size()) {
            return smallHeap.top();
        } else {
            return largeHeap.top();
        }
    }
};


//Sliding Window Median
//https://leetcode.com/problems/sliding-window-median/

//IPO
//https://leetcode.com/problems/ipo/
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> maxProfit; // Max heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minCapital; // Min heap

        for (int i = 0; i < capital.size(); i++) {
            minCapital.emplace(capital[i], profits[i]);
        }

        for (int i = 0; i < k; i++) {
            while (!minCapital.empty() && minCapital.top().first <= w) {
                maxProfit.push(minCapital.top().second);
                minCapital.pop();
            }
            if (maxProfit.empty()) {
                break;
            }
            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};