/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solveUsingRec(Node*root, vector<int>&postOrderAns) {
        if(!root)
            return;
        
        // traverse from left to right
        for(int i=0;i<root->children.size(); i++) {
            auto child = root->children[i];
            solveUsingRec(child, postOrderAns);
            postOrderAns.push_back(child->val);
        }

    }
    
    vector<int> postorder(Node* root) {
        vector<int>postOrderAns;

        solveUsingRec(root, postOrderAns);
        if(root)
            postOrderAns.push_back(root->val);
        return postOrderAns;
    }
};