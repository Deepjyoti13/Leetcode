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
    TreeNode* buildTree(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend, unordered_map<int, int>& inMap) {
        if(prestart>preend || instart>inend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = inMap[root->val];
        int numsleft = inroot-instart;
        root->left = buildTree(preorder, prestart+1, prestart+numsleft, inorder, instart, inroot-1, inMap);
        root->right = buildTree(preorder, prestart+numsleft+1, preend, inorder, inroot+1, inend, inMap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for(int i=0; i<inorder.size(); i++)
            inMap[inorder[i]] = i;
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    }
};

// 9 1 2 4
// 1 9 2 4