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
        ListNode* temp = head;
        int count = 0;
        while(temp) {
            count++;
            temp = temp->next;
        }

        return count;

    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, bool>mp; //to check the value from ll
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]] = true;
        }

        int length = getLength(head);

        ListNode* newHead = NULL;
        ListNode* nxt = NULL;
        ListNode* temp = head;
        while(temp) {
            if(mp.find(temp->val) == mp.end()) {
                //  it means we can add this node to the ans list
                if(newHead == NULL) {
                    // we are processing the very first node
                    newHead = temp;
                    nxt = newHead;
                }

                else {
                    // it means we have to add new node after the newHead
                    nxt->next = temp;
                    nxt = nxt->next;
                }
            }

            temp = temp->next;
        } 
        nxt->next = NULL;
        return newHead;
    }
};