#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0; 
        int goal = (1 << n) - 1;
        
        
        queue<pair<int, int>> q;
        
        
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
        
        
        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i});     
            visited[i][1 << i] = true; 
        }
        
        int steps = 0;
        
        
        while (!q.empty()) {
            int size = q.size();
            
            while (size--) {
                auto [curr_node, curr_mask] = q.front();
                q.pop();
                
               
                if (curr_mask == goal) {
                    return steps;
                }
                
                
                for (int neighbor : graph[curr_node]) {
                    
                    int next_mask = curr_mask | (1 << neighbor);
                    
                    
                    if (!visited[neighbor][next_mask]) {
                        visited[neighbor][next_mask] = true;
                        q.push({neighbor, next_mask});
                    }
                }
            }
            steps++; 
        }
        
        return -1;
    }
};
