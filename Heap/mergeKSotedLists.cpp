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
class compare {
    public:
    bool operator() (ListNode*a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;

        for(int i=0; i<lists.size(); i++) {
            ListNode* listHead = lists[i];
            //catch-> agr list empty h toh usko nhi dalna 
            if(listHead != NULL)
                pq.push(listHead);
        }

        // for new linked list
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(!pq.empty()) {
            ListNode* topNode = pq.top();
            pq.pop();

            // ye frontNode hmari first Node ho
            if(head == NULL) {
                head =  topNode;
                tail = topNode;
                if(topNode->next != NULL) {
                    pq.push(topNode->next);
                }

            }

            else {
                tail->next = topNode;
                tail = topNode;
                if(topNode->next != NULL) {
                    pq.push(topNode->next);
                }
            }
        }

        return head;
    }
};