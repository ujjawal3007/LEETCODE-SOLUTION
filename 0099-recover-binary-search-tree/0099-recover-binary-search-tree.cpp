#include <iostream>
#include <algorithm>

using namespace std;

/*
// LeetCode द्वारा पहले से डिफाइन की गई TreeNode संरचना:
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
*/

class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = new TreeNode(INT_MIN); 


    void inorder(TreeNode* root) {
        if (!root) return;

        
        inorder(root->left);

        
        if (root->val < prev->val) {
            
            if (!first) {
                first = prev;
            }
            
            second = root;
        }
        
        
        prev = root;

        
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        
        inorder(root);

        
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};
