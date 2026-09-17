class Solution {
public:
void getAllSubsets(vector<int>& nums, vector<int> ans, int i, vector<vector<int>>& AllSubsets) {
    if(i == nums.size()) {
        AllSubsets.push_back(ans);
        return;
    }
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i + 1, AllSubsets);
    ans.pop_back();
    int idx = i + 1;
    while(idx < nums.size() && nums[idx] == nums[idx - 1]) idx++;
    getAllSubsets(nums, ans, idx, AllSubsets);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> AllSubsets;
        vector<int> ans;
        getAllSubsets(nums, ans, 0, AllSubsets);
        return AllSubsets;
    }
};