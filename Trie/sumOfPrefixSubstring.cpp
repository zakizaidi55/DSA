class TrieNode {
    public:
        char data;
        unordered_map<char, TrieNode*>children;
        int countP;
        TrieNode(char ch) : data(ch), countP(0){}
};


class Trie {
        TrieNode* root;
        void insertUtils(TrieNode*root, string&word, int i=0) {
            if(i == word.size()) {
                return;
            }


            if(root->children.find(word[i]) == root->children.end()) {
                // not found
                root->children[word[i]] = new TrieNode(word[i]);
                root->children[word[i]]->countP += 1;  
                //cout << "word[i] " << word[i]  <<" root->children[word[i]]->countP " << root->children[word[i]]->countP << endl;
            }

            else {
                // found
                root->children[word[i]]->countP += 1;
            }

            insertUtils(root->children[word[i]], word, i+1);
        }

        int searchUtil(TrieNode*root, string&word, int i=0) {
            if(i == word.size()) { 
                return 0;
            }
            int count = 0;
            auto ch = word[i];
            // cout << "word[i] " << word[i]  <<" root->children[ch]->countP " << root->children[ch]->countP << endl;
            count = root->children[ch]->countP + searchUtil(root->children[ch], word, i+1);

            return count;
            
        }

    public:
        Trie() {
            root = new TrieNode('\0');
        }
        void insert(string&word) {
            insertUtils(root, word);
        }


        int search(string&word) {
            return searchUtil(root, word);
        }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        

        for(int i=0; i<words.size(); i++) {
            trie.insert(words[i]);
        }

        vector<int>ans(words.size());

        for(int i=0; i<words.size(); i++) {
            ans[i] = trie.search(words[i]);
        }


        return ans;
    }
};