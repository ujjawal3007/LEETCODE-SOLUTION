#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class MedianFinder {
private:
    
    priority_queue<int> small;
    
    
    priority_queue<int, vector<int>, greater<int>> large;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        small.push(num);
        
        
        if (!small.empty() && !large.empty() && small.top() > large.top()) {
            large.push(small.top());
            small.pop();
        }
        
    
        if (small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        } else if (large.size() > small.size() + 1) {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        
        if (small.size() > large.size()) {
            return small.top();
        } else if (large.size() > small.size()) {
            return large.top();
        }
        
    
        return (small.top() + large.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
