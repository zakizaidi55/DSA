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
    
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*>res;
        int len = 0;
        ListNode* head = new ListNode(0);
        ListNode* pre = root;
        ListNode* cur = head;
        ListNode* next;
        ListNode* p = root;
        while(p && ++len) p = p->next;
        int m = len % k, l = len / k;
        while(k--){
            cur->next = pre;
            for(int i = 0; i < l; i++) cur = cur->next;
            if(m)
             cur = cur->next, m--;
            next = cur->next;
            cur->next = NULL;
            res.push_back(pre);
            pre = next;
            cur = head;
        }
        return res;
    }
};
