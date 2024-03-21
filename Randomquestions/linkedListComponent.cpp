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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> st;
        for(int num: nums)
            st.insert(num);

        int res = 0, cur = 0;
        ListNode *curNode = head;
        while(curNode != NULL){
            if(st.find(curNode->val) != st.end()){
                if(cur == 0)
                    res ++;
                cur ++;
            }
            else
                cur = 0;

            curNode = curNode->next;
        }
        return res;
    }
};
