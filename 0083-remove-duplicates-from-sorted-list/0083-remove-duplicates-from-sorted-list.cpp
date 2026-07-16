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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* temp = head;
        while(temp && temp->next!=NULL){
            ListNode* dup = temp;
            while(dup && dup->next!=NULL && dup->val == dup->next->val) dup = dup->next;
            temp->next = dup->next;
            temp = temp->next;
        }
        return head;
    }
};