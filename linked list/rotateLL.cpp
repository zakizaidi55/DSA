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
    int getLength(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }

        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        
        int len = getLength(head); 

        int actualRotation = k%len;
        if(actualRotation == 0) {
            return head;
        }

        int newLastNodePos = len - actualRotation - 1 ;

        ListNode* newHead = head;
        ListNode* newLastNode = head;

        for(int i=0; i<newLastNodePos; i++) {
            newLastNode = newLastNode->next;
        }

        newHead = newLastNode->next;
        newLastNode->next = NULL;

        ListNode* it = newHead;

        while(it->next) {
            it = it->next;
        } 

        it->next = head;
        return newHead;

    }
};