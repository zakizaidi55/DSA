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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans = {-1, -1};

        ListNode* prev = head;
        if(!prev)
            return ans;
        
        ListNode* curr = head->next;
        if(!curr) 
            return ans;
        
        ListNode* nxt = head->next->next;
        if(!nxt)
            return ans;
        
        int i = 1;
        int firstCp = -1;
        int lastCp = -1;
        int minDist = INT_MAX;
        while(nxt) {
            bool isCp = ((curr->val > prev->val && curr->val > nxt->val) ||
                           curr->val < prev->val && curr->val < nxt->val ) ? 
                           true : false;
            

            if(isCp && firstCp == -1) {
                firstCp = i;
                lastCp = i;
            }

            else if(isCp) {
                // one more critical point is found
                minDist = min(minDist, i-lastCp);
                lastCp = i;
            }

            i++;
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;

        }

        if(firstCp == lastCp)
            return ans;
        
        else {
            ans[0] = minDist;
            ans[1] = lastCp - firstCp;
        }

        return ans;
    }
};