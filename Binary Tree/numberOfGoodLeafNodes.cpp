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
    void makeGraph(TreeNode*root, TreeNode*prevNode, unordered_map<TreeNode*, vector<TreeNode*> >&adj, unordered_set<TreeNode*>&st) {
        if(root == NULL)
            return;
        
        if(!root->left && !root->right) {
            // leaf node
            st.insert(root);
        }

        if(prevNode) {
            adj[root].push_back(prevNode);
            adj[prevNode].push_back(root);
        }

        makeGraph(root->left, root, adj, st);
        makeGraph(root->right, root, adj, st);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*> >adj;
        unordered_set<TreeNode*>st;

        makeGraph(root, NULL, adj, st);

        int count = 0;
        for(auto leaf: st) {
            queue<TreeNode*>q;
            unordered_set<TreeNode*>vis;
            q.push(leaf);
            vis.insert(leaf);
        

            for(int i=0; i<=distance; i++) {
                int size = q.size();
                while(size--) {
                    TreeNode*curr = q.front();
                    q.pop();

                    if(curr != leaf && st.count(curr)) {
                        count++;
                    }

                    for(auto nbr: adj[curr]) {
                        if(!vis.count(nbr)) {
                            q.push(nbr);
                            vis.insert(nbr);
                        }
                    }
                }
            }
        }

        return count/2;
    }
};