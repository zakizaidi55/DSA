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
    ListNode* mergeNodes(ListNode* head) {
        if (!head)
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* lastNode = NULL;

        int sum = 0;
        while(fast) {
            if(fast->val != 0) {
                sum += fast->val;

            }

            else {
                // fast->val == 0
                slow->val = sum;
                lastNode = slow;
                slow = slow->next;
                sum = 0;
            }


            fast = fast->next;
        }

        ListNode* temp = lastNode->next;
        // set the lastNode->next of linked list to the NULL
        lastNode->next = NULL;

        // catch for the good practice 
        // memory free for the remaing linked list

        while(temp) {
            ListNode* nxt = temp->next;
            delete temp;
            temp = nxt;
        }

        return head;
    }
};