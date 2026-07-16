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
        ListNode* dummy = new ListNode(200 , head);
        ListNode* temp = dummy;
        ListNode* ans = dummy;

        while(temp && temp->next!=NULL){
            while(temp && temp->next!=NULL && temp->val == temp->next->val){
                temp = temp->next;
            }
            dummy->next = temp->next;
            temp = temp->next;
            if(temp && temp->next!=NULL && temp->val == temp->next->val) continue;
            dummy = dummy->next;
        }
        return ans->next;
    }
};