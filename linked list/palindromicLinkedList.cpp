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
    ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr) {
        if(curr == NULL) {
            return prev;
        }
        
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;


        return reverseUsingRecursion(prev, curr);
        
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL) {
            fast = fast->next;
            if(fast->next != NULL) {
                fast = fast->next;
                // main yha keh sakta hu fast ne 2 step chal liye hai
                slow = slow->next;
            }
        }

        return slow;
    }


    bool compareList(ListNode* head1, ListNode* head2) {
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        while(temp1 != NULL && temp2 != NULL) {
            if(temp1->val != temp2->val) {
                return false;
            }

            else {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }

        }

        return true;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* midNode = middleNode(head);
        ListNode* head2 = midNode->next;

        midNode->next = NULL;

        ListNode* prev = NULL;
        ListNode* curr = head2;
        head2 = reverseUsingRecursion(prev, curr);

        bool ans = compareList(head, head2);

        return ans;

    }
};