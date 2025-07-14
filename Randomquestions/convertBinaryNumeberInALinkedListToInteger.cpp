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
    ListNode* reverseLL(ListNode* curr, ListNode* prev) {
        if(curr == NULL)
            return prev;
        
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;

        return reverseLL(curr, prev);
    }
    int getDecimalValue(ListNode* head) {
        ListNode* prev = NULL;
        head = reverseLL(head, prev);
        int result = 0;
        int power = 0;
        ListNode* temp = head;
        while(temp) {
            if(temp->val == 1) {
                result += pow(2, power);
            }
            power++;
            temp = temp->next;
        }

        return result;
    }
};


