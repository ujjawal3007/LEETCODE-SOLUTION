class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        
        
        if (n == 1) {
            return 1;
        }
        
      
        queue<pair<int, pair<int, int>>> q;
        
        
        grid[0][0] = 1;
        q.push({1, {0, 0}});
        
       
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int len = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            
            for (int i = 0; i < 8; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];
                
                
                if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 0) {
                    
                    
                    if (newr == n - 1 && newc == n - 1) {
                        return len + 1;
                    }
                    grid[newr][newc] = 1;
                    q.push({len + 1, {newr, newc}});
                }
            }
        }
        
        
        return -1;
    }
};
