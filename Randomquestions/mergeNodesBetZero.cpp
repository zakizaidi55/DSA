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
        if(!head)
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* newLastNode = NULL;
        int sum = 0;
        while(fast) {
            if(fast->val != 0) {
                sum += fast->val;
            }

            else {
                // fast->val == 0
                slow->val = sum;
                newLastNode = slow;
                slow = slow->next;
                sum = 0;
            }

            fast = fast->next;
        }

        ListNode* temp = newLastNode->next;
        newLastNode->next = NULL;

        // delete old list to prevent memory leak
        while(temp) {
            ListNode* next = temp->next;
            delete temp;
            temp = next;
        }

        return head;
    }
};