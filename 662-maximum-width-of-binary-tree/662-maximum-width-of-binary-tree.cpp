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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int mx = 0;
        if(!root) return 0;
        queue<pair<TreeNode*, long long>> todo;
        todo.push({root, 0});
        while(!todo.empty()) {
            int size = todo.size(), first, last;
            int mn = todo.front().second;
            for(int i=0; i<size; i++) {
                auto front = todo.front();
                todo.pop();
                TreeNode* node = front.first;
                long long height = front.second-mn;
                if(i==size-1) last = height;
                if(i==0) first = height;
                if(node->left)
                    todo.push({node->left, 2*height+1});
                if(node->right)
                    todo.push({node->right, 2*height+2});
            }
            mx = max(mx, last-first+1);
        }
        return mx;
    }
};