#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct Element {
    int val;       
    int listIdx;   
    int elemIdx;   
    bool operator>(const Element& other) const {
        return val > other.val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Element, vector<Element>, greater<Element>> minHeap;
        
        int currentMax = INT_MIN;
        int rangeStart = 0;
        int rangeEnd = INT_MAX;
        

        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }
        
        
        while (minHeap.size() == nums.size()) {
            Element curr = minHeap.top();
            minHeap.pop();
            
            
            if ((long long)currentMax - curr.val < (long long)rangeEnd - rangeStart) {
                rangeStart = curr.val;
                rangeEnd = currentMax;
            }
            
            
            if (curr.elemIdx + 1 < nums[curr.listIdx].size()) {
                int nextVal = nums[curr.listIdx][curr.elemIdx + 1];
                minHeap.push({nextVal, curr.listIdx, curr.elemIdx + 1});
                currentMax = max(currentMax, nextVal);
            }
        }
        
        return {rangeStart, rangeEnd};
    }
};
