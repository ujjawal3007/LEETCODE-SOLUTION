class Solution {
public:
    int binSearch(vector<int>& nums, int st, int end, int tar){
    if(st <= end) {
        int mid = st + (end - st) / 2;
        if(nums[mid] == tar) return mid;
        else if(tar > nums[mid]) {
           return binSearch(nums, mid + 1, end, tar);
        }
        else{
           return binSearch(nums, st, mid -1, tar);
        }
    }
    return -1;
}
    int search(vector<int>& nums, int tar) {
       return binSearch(nums, 0, nums.size() - 1, tar);
        
    }
};