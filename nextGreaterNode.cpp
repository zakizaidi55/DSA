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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ll;
        while(head) {
            ll.push_back(head->val);
            head = head->next;
        }
        stack<int> st;
        // vector<int> ans(ll.size(),0);
        
        for(int i=0; i<ll.size(); i++) {
            while(!st.empty() && ll[i] > ll[st.top()]) {
                // means ith element is the next greater element present in stack
                int element = st.top();
                st.pop();
                ll[element] = ll[i]; 
            }

            st.push(i);
        }
        while(!st.empty()) {
            ll[st.top()] = 0;
            st.pop();
        }
        ll[ll.size() - 1] = 0;

        return ll;
    }
};