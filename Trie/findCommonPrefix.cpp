class TrieNode{
    public:
        char value;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;

        TrieNode(char val) {
            this->value = val;
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            this->isTerminal = false;
            this->childCount = 0;

        }
};


class Solution {
public:
       
    void insertTrieNode(TrieNode* root, string word) {
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // 1 case
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;

        if(root->children[index] != NULL) {
            child = root->children[index];
        }

        else {
            child = new TrieNode(ch);
            root->children[index] = child;
            root->childCount++;
            
        }

        // recursion call
        insertTrieNode(child, word.substr(1));
    }

    bool searchWord(TrieNode* root, string word) {
        if(word.length() == 0) {
            return root->isTerminal;
        }

        char ch = word[0];
        int index = ch - 'a';

        TrieNode* child;

        if(root->children[index] != NULL) {
            child = root->children[index];
        }

        else {
            return false;
        }

        // recursion
        bool recAns = searchWord(child, word.substr(1));
        return recAns;
    }

    void deleteWord(TrieNode* root, string word) {
        if(word.length() == 0) {
            root->isTerminal = false;
            return;
        }

        // 1 case mera
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;

        if(root->children[index] != NULL) {
            child = root->children[index];
        }

        else {
            return;
        }

        // recursion
        deleteWord(child, word.substr(1));
    }

    void findLCP(string& ans, TrieNode* root) {

        // base case
        if(root->isTerminal == true)
            return;
        
        TrieNode* child;
        // Abhi m root par hu
        if(root->childCount == 1) {
            // cout <<"root->value "  << root->value << endl;
            // reach till the child and store it
            for(int i=0; i<26; i++) {
                if(root->children[i] != NULL) {
                    child = root->children[i];
                }
            }
            // cout << "child->value " << child->value << endl;
            ans.push_back(child->value);
        }

        else {
            return;
        }

        // call rec
        findLCP(ans, child);
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');

        for(auto str:strs) {
            insertTrieNode(root,str);

        }
        string ans = "";
        findLCP(ans, root);

        return ans;
    }
};