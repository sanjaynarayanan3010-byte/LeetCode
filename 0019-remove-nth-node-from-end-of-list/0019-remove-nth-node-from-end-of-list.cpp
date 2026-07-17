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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int ListCount = 0;
        ListNode* temp = head;
        ListNode* dummy = new ListNode(0, head);
        while(temp) {
            ListCount++;
            temp = temp->next;
        }
        int currPos = 0;
        temp = dummy;
        while(currPos != (ListCount-n)){
            currPos++;
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return dummy->next;
    }
};