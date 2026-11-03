#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       
        vector<vector<int>> adj(numCourses);
       
        vector<int> indegree(numCourses, 0); 
        
        for (auto& edge : prerequisites) {
            int course = edge[0];
            int pre = edge[1];
            
            adj[pre].push_back(course); 
            indegree[course]++; 
        }
        
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        
        int processedCourses = 0; 
        
       
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            processedCourses++; 
            for (int neighbour : adj[curr]) {
                indegree[neighbour]--; 
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        
        
        return processedCourses == numCourses;
    }
};
