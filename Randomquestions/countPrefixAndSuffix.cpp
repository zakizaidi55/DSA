class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode*children[26];

    TrieNode(char ch):data(ch), isTerminal(false){
        for(int i=0;i<26;++i){
            children[i] = 0;
        }
    }
};

class Trie {
    TrieNode*root;

    void insertUtil(TrieNode*root, string&word, int i){
        if(i >= word.size()){
            root->isTerminal = 1;
            return;
        }

        int index = word[i] - 'a';
        if(!root->children[index])
            root->children[index] = new TrieNode(word[i]);

        insertUtil(root->children[index], word, i + 1);
    }

    bool searchUtil(TrieNode*root, string&word){
        TrieNode* pCrawl = root;
        for(int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if(pCrawl->children[idx] == NULL) {
                return false;
            }
            pCrawl = pCrawl->children[idx];
        }

        return true;
    }

    public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word) {
        insertUtil(this->root, word, 0);
    }

    bool search(string word) {
        return searchUtil(this->root, word);
    }

};
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();

        int count = 0;

        for(int j = 0; j < n; j++) {
            Trie prefixTrie; 
            Trie suffixTrie; 

            prefixTrie.insert(words[j]);
            string reversed = words[j];
            reverse(reversed.begin(), reversed.end());

            suffixTrie.insert(reversed);

            for(int i = 0; i < j; i++) {
                if(words[i].length() > words[j].length() || i == j) {
                    continue;
                }

                string rev = words[i];
                reverse(rev.begin(), rev.end());

                if(prefixTrie.search(words[i]) == true && suffixTrie.search(rev) == true) {
                    count++;
                }
            }
        }

        return count;
    }
};