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
    // int getLength(ListNode* list) {
    //     ListNode* temp = list;
    //     int count = 0;
    //     while(temp) {
    //         count++;
    //         temp = temp->next;
    //     }

    //     return count;
    // }
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // int len1 = getLength(list1);
        // int len2 = getLength(list2);

        ListNode* ptr = list1;
        for(int i=0; i<a-1; i++) {
            if(ptr->next) {
                ptr = ptr->next;
            } 
        }

        ListNode* ptr2 = ptr->next;

        for(int i=0; i<b-a+1; i++) {
            if(ptr2->next) {
                ptr2 = ptr2->next;
            }
        }

        ptr->next = list2;
        while(list2->next) {
            list2 = list2->next;
        }

        list2->next = ptr2;


        return list1;
    }
};