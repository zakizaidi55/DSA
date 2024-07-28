/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool>mp;
        ListNode* temp = head;

        while(temp) {
            if(mp[temp] == true) 
                return temp;
            
            else {
                mp[temp] = true;
            }

            temp = temp->next;
        }

        return NULL;

    }
};