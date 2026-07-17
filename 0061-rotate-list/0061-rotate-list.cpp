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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || !head) return head;
        int listCount = 0;
        ListNode* temp = head;
        while(temp) {
            if(temp->next == NULL) {
                listCount++;
                temp->next = head;
                break;
            }
            temp = temp->next;
            listCount++;
        }

        int rotateNo = k % listCount;
        int currPos = 0;
        cout<<rotateNo<<" "<<listCount;

        temp = head;
        while(currPos != listCount - rotateNo - 1){
            currPos++;
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};