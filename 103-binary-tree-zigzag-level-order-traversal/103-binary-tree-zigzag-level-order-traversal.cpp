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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>> ();
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        bool count=false;
        while(!q.empty()) {
            int size = q.size();
            int temp = size;
            vector<int> ans(size);
            while(size--) {
                TreeNode* front = q.front();
                q.pop();
                count?ans[temp-size-1]=front->val:ans[size]=front->val;
                // ans.push_back(front->val);
                if(front->right)
                    q.push(front->right);
                if(front->left)
                    q.push(front->left);

            }
            count = !count;
            res.push_back(ans);
        }
        return res;
    }
};



