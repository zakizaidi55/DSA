
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
    int maxLevelSum(TreeNode* root) {
        int sum = INT_MIN;
        int ans = 0;
        queue<pair<TreeNode*, int> >q;

        q.push({root, 1});

        while(!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;
            int level = 0;
            for(int i=0; i<levelSize; i++) {
                auto frontNode = q.front();
                q.pop();
                levelSum += frontNode.first->val;
                level = frontNode.second;

                if(frontNode.first->left) 
                    q.push({frontNode.first->left, level+1});
                
                if(frontNode.first->right) 
                    q.push({frontNode.first->right, level+1});
            }

            if(levelSum > sum) {
                sum = levelSum;
                ans = level;
            }
        }

        return ans;
    }
};


