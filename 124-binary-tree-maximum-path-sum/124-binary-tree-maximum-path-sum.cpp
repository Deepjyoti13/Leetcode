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
    int height(TreeNode* root, int& mx) {
        if(!root) return 0;
        int lh = max(0, height(root->left, mx));
        int rh = max(0, height(root->right, mx));
        mx = max(mx, root->val + lh + rh);
        return root->val+max(lh,rh);
    }
public:
    int maxPathSum(TreeNode* root) {
        int mx = root->val;
        height(root, mx);
        return mx;
    }
};
































