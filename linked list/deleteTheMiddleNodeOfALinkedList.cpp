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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head)
            return NULL;
        
        if(head->next == NULL)  {
            // delete head;
            return NULL;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;

        while(fast != NULL) {
            fast = fast->next;
            if(fast != NULL) {
                if(slow != head) {
                    prev = prev->next;
                }   
                slow = slow->next;
                fast = fast->next;
            }
        } 

        prev->next = slow->next;

        delete slow;

        return head;
    }
};


