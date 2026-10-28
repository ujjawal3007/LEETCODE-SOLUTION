#include <queue>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

       
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> min_heap;
        
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();
            long long level_sum = 0;

            
            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                level_sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            
            min_heap.push(level_sum);

        
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        
        if (min_heap.size() < k) {
            return -1;
        }

    
        return min_heap.top();
    }
};
