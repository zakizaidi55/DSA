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
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

        }
        return slow;
    }

     ListNode* merge(ListNode* list1, ListNode* list2) {
        if(list1 == NULL )
            return list2;
        
        if(list2 == NULL)
            return list1;
        
        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        while(list1 && list2) {
            if(list1->val <= list2->val) {
                mptr->next = list1;
                mptr = list1;
                list1 = list1->next; 
            }

            else {
                mptr->next = list2;
                mptr = list2;
                list2 = list2->next;
            }
        }

      
        if(list1) {
            mptr->next = list1;
            
        }

        if(list2) {
            mptr->next = list2;

        }

        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) 
            return head;
        
        // break LL into two half using mid
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        // sort using recursion
        left = sortList(left);
        right = sortList(right);

        // merge both the linked list
        ListNode* mergeLL = merge(left, right);
        return mergeLL;
    }
};