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

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }

        if (root->val == key) {
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;

            }
            // root->left == NULL and root->right != NULL
            else if(!root->left) {
                TreeNode* child = root->right;
                delete root;
                return child;
            }

            else if(!root->right) {
                TreeNode* child = root->left;
                delete root;
                return child;
            }

            else {

                // right subtree ka min
                TreeNode* rScan = root->right;
                while(rScan->left) {
                    rScan = rScan->left;
                }

                rScan->left = root->left;
                TreeNode* temp = root;
                root = root->right;
                delete temp;

                return root;
         
                
            }
        }

        else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        } 

        else {
            root->left = deleteNode(root->left, key);
        }

        return root;
    }
};


// ------------------------------------------------------Method 2---------------------------------

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
    TreeNode* maxValue(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }

        TreeNode* temp = root;

        while(temp->right != NULL) {
            temp = temp->right;
        }

        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }

        if (root->val == key) {
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;

            }
            // root->left == NULL and root->right != NULL
            else if(!root->left) {
                TreeNode* child = root->right;
                delete root;
                return child;
            }

            else if(!root->right) {
                TreeNode* child = root->left;
                delete root;
                return child;
            }

            else {
                TreeNode* maxi = maxValue(root->left);
                root->val = maxi->val;
                root->left = deleteNode(root->left, maxi->val);
                return root;
            }
        }

        else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        } 

        else {
            root->left = deleteNode(root->left, key);
        }

        return root;
    }
};