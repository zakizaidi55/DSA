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
    ListNode* insertionSortList(ListNode* head) {
        if(!head)
            return head;
            ListNode* current = head ->next;
            ListNode* pre = head;
            while(current)
            {
                ListNode* temp2 = head;
                ListNode* temp1 = head;
                while(temp2 ->val < current ->val)
                {
                    temp1 = temp2;
                    temp2 = temp2 ->next;
                }
                if(temp1 != temp2)
                    temp1 ->next = current;
                else
                    head = current;
                if(temp2 != current)
                {
                    pre ->next = current ->next;
                    current ->next = temp2;
                    current = pre ->next;
                }
                else
                {
                    pre = current;
                    current = current ->next;
                }
            }
        
        return head;
    }
};