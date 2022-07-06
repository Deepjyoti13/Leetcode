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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *prev = dummy, *curr = dummy, *next;
        int count = 0;
        while(curr->next) {
            curr = curr->next;
            count++;
        }
        while(count>=k) {
            curr = prev->next;
            next = curr->next;
            for(int i=1; i<k; i++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            count-=k;
        }
        return dummy->next;
        // dummy->next will store the head of k-reversed LL because prev is pointing to the address of dummy, wherever prev->next points, dummy->next points to the same address but at line 33 (after first k-reverse is done) prev points to a whole new location so dummy->next no longer points to the same location where prev->next points to. Same with curr and next in line 25 and 26 if you initiate curr and next to the location of dummy.
    }
};