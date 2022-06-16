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
        // if(!root->left && !root->left) return 1;
        int mx = 0;
        if(!root) return 0;
        queue<pair<TreeNode*, pair<long, long>>> todo;
        map<long long, pair<long long, long long>> nodes;
        todo.push({root, {1, 0}});
        while(!todo.empty()) {
            long long size = todo.size();
            long long mn = todo.front().second.first;
            while(size--) {
                auto front = todo.front();
                todo.pop();
                TreeNode* node = front.first;
                long long height = front.second.first;
                long long level = front.second.second;
                height = height-mn;
                nodes[level] = {min(nodes[level].first, height), max(nodes[level].first, height)};
                mx = max(mx*1LL, nodes[level].second-nodes[level].first+1);
                if(node->left)
                    todo.push({node->left, {2*height, level+1}});
                if(node->right)
                    todo.push({node->right, {2*height+1, level+1}});
            }
        }
        return mx;
    }
};
