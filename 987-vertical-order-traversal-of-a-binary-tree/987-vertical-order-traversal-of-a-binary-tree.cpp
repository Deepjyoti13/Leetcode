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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> todo;
        map<int, map<int, multiset<int>>> nodes;
        todo.push({root, {0, 0}});
        while(!todo.empty()) {
            auto front = todo.front();
            todo.pop();
            TreeNode* node = front.first;
            int level = front.second.first;
            int height = front.second.second;
            nodes[level][height].insert(node->val);
            if(node->left) {
                todo.push({node->left, {level-1, height+1}});
            }
            if(node->right) {
                todo.push({node->right, {level+1, height+1}});
            }
        }
        vector<vector<int>> res;
    
        for(auto p: nodes) {
            vector<int> ans;
            for(auto q: p.second) {
                for(int i: q.second) {
                    ans.push_back(i);
                }
            }
            res.push_back(ans);
        }

        return res;
    }
};