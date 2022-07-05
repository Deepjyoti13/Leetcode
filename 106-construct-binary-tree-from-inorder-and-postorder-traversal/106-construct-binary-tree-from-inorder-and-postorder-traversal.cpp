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
    TreeNode* buildTree(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend, unordered_map<int, int>& inMap) {
        if(instart>inend || poststart>postend) return NULL;
        TreeNode* root = new TreeNode(postorder[postend]);
        int inroot = inMap[root->val];
        int numsleft = inroot-instart;
        root->left = buildTree(inorder, instart, inroot-1, postorder, poststart, poststart+numsleft-1, inMap);
        root->right = buildTree(inorder, inroot+1, inend, postorder, poststart+numsleft, postend-1, inMap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for(int i=0; i<inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);
    }
};

// 40 20 50 10 60 30
// 40 50 20 60 30 10