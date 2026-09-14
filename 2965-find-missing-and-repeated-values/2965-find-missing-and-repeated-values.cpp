class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
      vector<int> ans;
      unordered_set<int> m;
      int n = grid.size();
      int a, b;
      int expSum = 0;
      int actualSum = 0;  
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            actualSum += grid[i][j];
            if(m.find(grid[i][j]) != m.end()) {
                a = grid[i][j];
                ans.push_back(a);
            }
            m.insert(grid[i][j]);
        }
      }
      expSum = (n * n) * (n * n + 1)/ 2;
      b = expSum + a - actualSum;
      ans.push_back(b);
      return ans;
    }
};