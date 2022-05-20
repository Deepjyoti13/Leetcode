/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */



struct compare {
    bool operator()(ListNode* l, ListNode* r) {
        return l->val > r->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int N = lists.size();
        if(!N) return NULL;
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;
        ListNode* root = NULL;
        ListNode* tmp = root;
        for(int i=0; i<N; i++)
            if(lists[i])
                pq.push(lists[i]);
        while(!pq.empty()) {
            ListNode* node = pq.top();
            if(!root) {
                root = node;
                tmp=root;
            }
            else {
                tmp->next = node;
                tmp=tmp->next;
            }
            pq.pop();
            if(node->next) {
                pq.push(node->next);
                // node = node->next;
            }
        }
        return root;
    }
};























