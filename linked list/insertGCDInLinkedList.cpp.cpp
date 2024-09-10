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
    int gcd(int A, int B) {
        if(A == 0) 
            return B;
        
        if(B == 0)
            return A;
        

        while(A > 0 && B > 0) {
            if(A > B) {
                A = A-B;
            }

            else  {
                B = B-A;
            }
        }

        return A == 0 ? B : A;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head)
            return NULL;
        
        if(!head->next) {
            return head;
        }

        ListNode* curr = head;
        ListNode* nxt = curr->next;

        while(nxt) {
            ListNode* divisor = new ListNode(gcd(curr->val, nxt->val));
            divisor->next = nxt;
            curr->next = divisor;
            curr = curr->next->next;
            nxt = curr->next;
        }

        return head;

    }
};