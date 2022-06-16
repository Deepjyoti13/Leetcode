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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return vector<int>();
        vector<int> res;
        queue<pair<TreeNode*, int>> todo;
        map<int, int> nodes;
        todo.push({root, 0});
        while(!todo.empty()) {
            auto front = todo.front();
            todo.pop();
            TreeNode* node = front.first;
            int level = front.second;
            nodes[level] = node->val;
            if(node->left) {
                todo.push({node->left, level+1});
            }
            if(node->right) {
                todo.push({node->right, level+1});
            }
        }
        for(auto i: nodes) {
            res.push_back(i.second);
        }
        return res;
    }
};