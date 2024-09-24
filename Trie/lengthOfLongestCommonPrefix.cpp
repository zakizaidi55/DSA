class TrieNode {
    public:
        char data;
        unordered_map<char, TrieNode*>children;
        bool isTerminal;
        TrieNode(char ch) : data(ch), isTerminal(false){}
};


class Trie {
        TrieNode* root;
        void insertUtils(TrieNode*root, string&word, int i=0) {
            if(i == word.size()) {
                root->isTerminal = true;
                return;
            }


            if(root->children.find(word[i]) == root->children.end()) {
                root->children[word[i]] = new TrieNode(word[i]);
            }

            insertUtils(root->children[word[i]], word, i+1);
        }

        int searchUtil(TrieNode*root, string&word, int i=0) {

            if(i >= word.length()) {
                return 0;
            }

            char ch = word[i];
            int count = 0;
            if(root->children.find(ch) != root->children.end()) {
                // present
                count = 1 + searchUtil(root->children[ch], word, i+1);  
            }

            return count;
        }

    public:
        Trie() {
            root = new TrieNode('\0');
        }
        void insert(int num) {
            string word = to_string(num);
            insertUtils(root, word);
        }


        int search(int num) {
            string word = to_string(num);
            return searchUtil(root, word);
        }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        for(int num: arr1) {
            trie.insert(num);
        }

        int result = 0;

        for(int num:arr2 ) {
            result = max(result, trie.search(num));
        }

        return result;
    }
};