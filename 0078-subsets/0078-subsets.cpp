class Solution {
public:
void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& AllSubsets) {
    if(i == nums.size()) {
        AllSubsets.push_back(ans);
        return;
    }
    // include
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i + 1, AllSubsets);

    ans.pop_back();

    //exclude
    getAllSubsets(nums, ans, i + 1, AllSubsets);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> AllSubsets;
        vector<int> ans;
        getAllSubsets(nums, ans, 0, AllSubsets);
        return AllSubsets;
    }
};