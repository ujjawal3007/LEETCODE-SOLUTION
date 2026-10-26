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
    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode, unordered_map<int, TreeNode*>& valToNode) {
        if (root == nullptr) return true;
        
        if (minNode && root->val <= minNode->val) return false;
        if (maxNode && root->val >= maxNode->val) return false;
        
        if (root->left == nullptr && root->right == nullptr && valToNode.count(root->val)) {
            int value = root->val;
            root->left = valToNode[value]->left;
            root->right = valToNode[value]->right;
            
            valToNode.erase(value);
        }
        
        return isValidBST(root->left, minNode, root, valToNode) && 
               isValidBST(root->right, root, maxNode, valToNode);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> valToNode;
        unordered_map<int, int> count;
        
        for (TreeNode* tree : trees) {
            valToNode[tree->val] = tree;
            count[tree->val]++;
            if (tree->left) count[tree->left->val]++;
            if (tree->right) count[tree->right->val]++;
        }
        
        TreeNode* globalRoot = nullptr;
        for (TreeNode* tree : trees) {
            if (count[tree->val] == 1) {
                globalRoot = tree;
                break;
            }
        }
        
        if (globalRoot == nullptr) return nullptr;
        
        valToNode.erase(globalRoot->val);
        
        if (isValidBST(globalRoot, nullptr, nullptr, valToNode) && valToNode.empty()) {
            return globalRoot;
        }
        
        return nullptr;
    }
};
