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

    int gcd(int A, int B) 
	{ 
	    if(A == 0)
	        return B;
	    
	    
	    if(B == 0) 
	        return A;
	        
	    while(A > 0 && B > 0) {
	       if(A > B)
    	       A = A - B;
    	       
    	   else 
    	       B = B - A;
	       
	    }
	    
	    return A == 0 ? B : A;  
	      
	} 
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
       if(head == NULL || head->next == NULL) 
            return head;
            
        ListNode* temp = head;
        while (temp->next != NULL) {
            ListNode* newNode = new ListNode(gcd(temp->val, temp->next->val));
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        return head;

    }
};