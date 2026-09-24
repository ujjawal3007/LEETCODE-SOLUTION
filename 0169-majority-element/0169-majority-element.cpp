class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int freq = 0;
       int count = 0;
       int n = nums.size(); 
       for(int i = 0; i < n; i++) {
        if(freq == 0) {
            count = nums[i];
        }
        if(count == nums[i]) {
            freq++;
        }
        else{
            freq--;
        }
    }
    return count;
    }
};