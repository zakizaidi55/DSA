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
    int length(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL) {

            temp = temp->next;
            cnt++;
        }

        return cnt;
    }
    TreeNode* solve(ListNode* &head, int n) {
        if(head)
            cout << "n value " << n << endl;;
        if(head == NULL || n <= 0) {
            return NULL;
        }

        // left subtree
        TreeNode* leftSubTree = solve(head, n/2);

        // current node
        int element = head->val;
        TreeNode* root = new TreeNode(element);
        root->left = leftSubTree;

        head = head->next;

        TreeNode* rightSubTree = solve(head, n-n/2-1);
        if(head)
            cout <<"in right call " << head->val << " n value "<< n<< endl;
        root->right = rightSubTree;

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n = length(head);

        return solve(head, n);
    }
};