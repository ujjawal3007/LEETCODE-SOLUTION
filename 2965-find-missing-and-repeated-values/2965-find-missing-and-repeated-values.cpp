class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> m;
        int n = grid.size();
        int a, b;
        int expsum = 0;
        int actualsum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                actualsum += grid[i][j];
                if(m.find(grid[i][j]) != m.end()) {
                    a = grid[i][j];
                    ans.push_back(a);
                }
                m.insert(grid[i][j]);
            }
        }
        expsum = (n * n) * (n * n + 1) / 2;
        b = expsum + a - actualsum;
        ans.push_back(b);
        return ans;
    }
};