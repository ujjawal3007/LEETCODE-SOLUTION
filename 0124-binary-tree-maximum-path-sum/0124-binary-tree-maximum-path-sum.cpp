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
int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
            maxGain(root);
            return maxSum;
        }
        int maxGain(TreeNode* root) {
            if(root == NULL) {
                return 0;
            }
            int left = max(0, maxGain(root -> left));
            int right = max(0, maxGain(root -> right));

            int currSum = root -> val + left + right;

            maxSum = max(maxSum, currSum);
            return root -> val + max(left, right);
        }
    };