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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(nums.begin(), nums.end());
        vector<int>v;
        ListNode* temp = head;
        while(temp) {
            if(st.find(temp->val ) == st.end()) {
                v.push_back(temp->val);
            }

            temp = temp->next;
        }

        ListNode* newHead = NULL;
        ListNode* tail = NULL;
        if(!v.empty()) {
            newHead = new ListNode(v[0]);
            tail = newHead;
        }

        for(int i=1; i<v.size(); i++) {
            tail->next = new ListNode(v[i]);
            tail = tail->next;
        }

        return newHead;
    }
};


