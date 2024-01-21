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

    bool searchUtil(TrieNode*root, string&word, int &i){
        if(root->isTerminal)
            return true;
        if(i >= word.size())
            return root->isTerminal;

        int index = word[i++] - 'a';
        if(root->children[index])
            return searchUtil(root->children[index], word, i);

        return false;
    }

    bool startsWithUtil(TrieNode*root, string&word, int i){
        if(i >= word.size())
            return true; // prefix found;

        int index = word[i] - 'a';
        if(root->children[index])
            return startsWithUtil(root->children[index], word, i + 1);

        return false;
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word) {
        insertUtil(this->root, word, 0);
    }

    int search(string word) {
        int i = 0;
        bool gotIt = searchUtil(root, word, i);
        return gotIt ? i: -1;
    }

    bool startsWith(string prefix) {
        return startsWithUtil(this->root, prefix, 0);
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        Trie trie;
        // insert the dict into trie
        for(auto root: dictionary) {
            trie.insert(root);
        }

        // pick each word and find the root is available or not
        int start = 0;
        int end = 0;
        while(end < sentence.size()) {
            if(sentence[end] == ' ' || end == sentence.size()-1) {
                int len = end == sentence.size() - 1 ? sentence.size() : end - start;
                string word = sentence.substr(start, len);
                int trieMatchIndex = trie.search(word);
                ans += trieMatchIndex != -1 ? word.substr(0, trieMatchIndex) : word;
                if(sentence[end] == ' ') {
                    ans += " ";
                }

                start = end+1;
            }

            end++;
        }

        return ans;
    }
};