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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int> >ans;
        queue<pair<TreeNode*, pair<int, int> > >q; //Node*, {row, col};
        q.push({root, {0,0}});

        map<int, map<int, multiset<int> > >mp; //col-> row->multiset

        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            TreeNode* node = front.first;
            auto& cordinates = front.second;

            int& row = cordinates.first;
            int& col = cordinates.second;
            mp[col][row].insert(node->val);

            if(node->left){
                q.push({node->left, {row+1, col-1}});
            }

            if(node->right){
                q.push({node->right, {row+1, col+1}});
            }
        }

        //store the ans in vector

        for(auto it: mp) {
            auto& colMap  = it.second;
            vector<int>vLine;
            for(auto colMapIt: colMap) {
                auto& mSet = colMapIt.second;
                vLine.insert(vLine.end(), mSet.begin(), mSet.end());

            }

            ans.push_back(vLine);
        }

        return ans;
    }
};