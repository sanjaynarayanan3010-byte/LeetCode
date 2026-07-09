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
    ListNode* reverseList(ListNode* head) {
        int currPos=1;
        ListNode* prev = NULL;
        ListNode* currHead = head;

        while(currHead){
            ListNode* temp = currHead->next;
            currHead->next = prev;
            prev = currHead;
            currHead = temp;
        }

        return prev;
    }
};