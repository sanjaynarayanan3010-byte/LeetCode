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
    ListNode* oddEvenList(ListNode* head) {
        int currPos=1;
        if(!head || head->next==NULL) return head;
        ListNode* oddNode = head;
        ListNode* evenNode = head->next;
        ListNode* temp = head->next;
        while(evenNode && oddNode && oddNode->next!=NULL && evenNode->next!=NULL){
            oddNode->next = oddNode->next->next;
            oddNode = oddNode->next;
            evenNode->next = evenNode->next->next;
            evenNode = evenNode->next;
        }
        oddNode->next = temp;
        return head;
    }
};