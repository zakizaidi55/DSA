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
    void reorderList(ListNode* head) {
        stack<ListNode*>s;
        ListNode*curr = head;
        
        while(curr) {
            s.push(curr);
            curr = curr->next;
        }
        // repoint curr to the head
        curr = head;

        unordered_map<ListNode*, bool>vis;
        while(true) {
            ListNode* lastNode = s.top();
            s.pop();
            ListNode* next = curr->next; // to keep the track of the linked list which is attached to the curr pointer
            vis[curr] = true;
            if(vis[lastNode]) {
                curr->next = NULL;
                break;
            }

            curr->next = lastNode;
            vis[lastNode] = true;
            curr = curr->next;

            if(vis[next]) {
                curr->next = NULL;
                break;
            }

            curr->next = next;
            curr = curr->next;
        }
    }
};