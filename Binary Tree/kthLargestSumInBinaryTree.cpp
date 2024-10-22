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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        priority_queue<long long, vector<long long>, greater<long long> >minHeap;

        while(!q.empty()) {
            int n = q.size();
            long long sum = 0;
            while(n--) {
                auto front = q.front();
                q.pop();
                sum += front->val;

                if(front->left) {
                    q.push(front->left);
                }

                if(front->right) {
                    q.push(front->right);
                }
            }

            minHeap.push(sum);

            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.size() < k ? -1 : minHeap.top();
    }
};