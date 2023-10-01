
// This is the solution for Find Median From Data Stream question from Leetcode
// https://leetcode.com/problems/find-median-from-data-stream/description/

class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap.size() > 0 && num > max_heap.top())
        {
            min_heap.push(num);
        }
        else
        {
            max_heap.push(num);
        }
        if(max_heap.size() > min_heap.size()+1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if(min_heap.size() > max_heap.size()+1)
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(max_heap.size() == min_heap.size())
        {
            return (max_heap.top()+min_heap.top())/2.0;
        }
        if(max_heap.size() > min_heap.size())
        {
            return max_heap.top();
        }
        else
        {
            return min_heap.top();
        }
    }
};