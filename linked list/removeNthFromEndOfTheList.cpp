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
    int countLength(ListNode*head) {
        int count = 0;
        while(head) {
            count++;
            head = head->next;
        }

        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = countLength(head);

        int nodeToDelete = length - n - 1;
        ListNode* curr = head;

        // important condition yahi mistake karta hu
        if(nodeToDelete == -1 ) {
            head = head->next;
            delete curr;
            return head;
        }

        while(nodeToDelete) {
            curr = curr->next;
            nodeToDelete--;
        }


        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;


        return head;
    }
};