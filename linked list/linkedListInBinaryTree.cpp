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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(ListNode*head, TreeNode* root) {
        if (!head) {
            return true;
        }
        
        if (!root) {
            return false;
        }


        return root->val == head->val &&
               (solve(head->next, root->left)
                || solve(head->next, root->right));

    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) 
            return false;

        if(!head)
            return true;

        // i have possibility

        // root se ans mil sakta hai ya root->left se mil sakta h ya root->right se mil sakta h

        return (solve(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right));
    }
};