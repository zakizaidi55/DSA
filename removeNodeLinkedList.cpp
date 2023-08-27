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
    ListNode* removeNodeHelper(ListNode* head) {
        if (head == NULL)
            return NULL;

        head->next = removeNodeHelper(head->next);
        return head->next != NULL && head->val < head->next->val ? head->next: head;
    }
    ListNode* removeNodes(ListNode* head) {
        return removeNodeHelper(head);
    }
};
