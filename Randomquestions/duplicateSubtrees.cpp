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
    vector<TreeNode*>ans;
    unordered_map<string, int> subTreeMap;
    string preorderTraversal(TreeNode* root) {
        if(!root)
            return "N";
        
        string curr = to_string(root->val);
        string left = preorderTraversal(root->left);
        string right = preorderTraversal(root->right);

        string s = curr + "," + left + "," + right;

        // find the occurence in the map
        if(subTreeMap.find(s) != subTreeMap.end()) {
            if(subTreeMap[s] == 1)
                ans.push_back(root);
            
            subTreeMap[s]++;
        }

        else {
          subTreeMap[s]++;
        }

        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preorderTraversal(root);
        return ans;
    }
};
