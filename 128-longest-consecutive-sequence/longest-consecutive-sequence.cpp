class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int lastSmaller = INT_MIN;
        int count = 0, longest = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] - 1 == lastSmaller) {
                count += 1;
                lastSmaller = nums[i];
            }
            else if(lastSmaller != nums[i]) {
                count = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest, count);
        }
        return longest;
    }
};