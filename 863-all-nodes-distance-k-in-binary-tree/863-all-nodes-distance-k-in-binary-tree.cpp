/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void markParents(TreeNode* root, map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            if(front->left) {
                q.push(front->left);
                parent[front->left] = front;
            }
            if(front->right) {
                q.push(front->right);
                parent[front->right] = front;
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        set<TreeNode*> visited;
        vector<int> res;
        markParents(root, parent);
        int curr=0;
        q.push(target);
        while(!q.empty()) {
            int size = q.size();
            if(curr++>=k) break;
            for(int i=0; i<size; i++) {
                auto front = q.front();
                q.pop();
                visited.insert(front);
                if(front->left && !visited.count(front->left)) {
                    q.push(front->left);
                }
                if(front->right && !visited.count(front->right)) {
                    q.push(front->right);
                }
                if(parent[front] && !visited.count(parent[front])) {
                    q.push(parent[front]);
                }
            }
        }
        while(!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};