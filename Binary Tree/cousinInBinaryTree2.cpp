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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>levelSum;

        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            int currLevelSum = 0;
            while(n--) {
                auto front = q.front();
                q.pop();
                currLevelSum += front->val;

                if(front->left) {
                    q.push(front->left);
                }

                if(front->right) {
                    q.push(front->right);
                }
            }

            levelSum.push_back(currLevelSum);
        }

        // here we have sum of all levels

        q.push(root);
        root->val = 0; //because root does not have any cousins

        // catch-> level0 upar already ho gya h, isliye 1 se start kar rahe h
        int i = 1;

        while(!q.empty()) {
            int n = q.size();
            while(n-- )  {
                auto front = q.front();
                q.pop();

                int sibblingSum = front->left ? front->left->val : 0;
                sibblingSum += front->right ? front->right->val : 0;

                // update the value
                if(front->left) {
                    front->left->val = levelSum[i] - sibblingSum;
                    q.push(front->left);
                }

                if(front->right) {
                    front->right->val = levelSum[i] - sibblingSum;
                    q.push(front->right);
                }
            }

            i++;
        }

        return root;

    }
};