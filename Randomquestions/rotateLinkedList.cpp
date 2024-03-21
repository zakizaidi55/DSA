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
        while(head) {
            len++;
            head = head->next;
        }

        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) {
            return NULL;
        }

        int len = getLength(head);
        int actualRotate = k%len;

        if(actualRotate == 0) {
            return head;
        }

        int newLastNodePos = len - actualRotate - 1;
       
        ListNode* newLastNode = head;
        for(int i=0; i<newLastNodePos;i++) {
            newLastNode = newLastNode->next;
        }
        ListNode* newHead = newLastNode->next;
        newLastNode->next = NULL;


        ListNode* it = newHead;
        while(it->next) {
            it = it->next;

        }
        it->next = head;
        return newHead;
    }

};