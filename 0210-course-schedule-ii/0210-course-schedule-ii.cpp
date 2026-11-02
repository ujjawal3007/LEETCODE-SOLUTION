#include <vector>
#include <algorithm>

class Solution {
private:
    
    bool hasCycle(int curr, std::vector<std::vector<int>>& adj, std::vector<int>& visited, std::vector<int>& order) {
        
        if (visited[curr] == 1) return true;
    
        if (visited[curr] == 2) return false;
        
        
        visited[curr] = 1;
        
       
        for (int neighbor : adj[curr]) {
            if (hasCycle(neighbor, adj, visited, order)) {
                return true; 
            }
        }
        
        
        visited[curr] = 2;
        
        
        order.push_back(curr);
        
        return false;
    }

public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        
        std::vector<std::vector<int>> adj(numCourses);
        for (const auto& edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];
            adj[prereq].push_back(course); 
        }
        
        
        std::vector<int> visited(numCourses, 0);
        std::vector<int> order; 
        
        
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) {
                if (hasCycle(i, adj, visited, order)) {
                    return {}; 
                }
            }
        }
        
        
        std::reverse(order.begin(), order.end());
        
        return order;
    }
};
