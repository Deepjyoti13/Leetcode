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
    pair<int, int> helper(TreeNode* root) {
        if(!root) return {0, 0};
        pair<int, int> left = helper(root->left);
        pair<int, int> right = helper(root->right);
        return {max(left.first, left.second) + max(right.first, right.second), root->val + left.first + right.first};
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> res = helper(root);
        return max(res.first, res.second);
    }
};