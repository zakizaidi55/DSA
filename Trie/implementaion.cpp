#include<iostream>

using namespace std;

class TrieNode{
    public:
        char value;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char val) {
            this->value = val;
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            this->isTerminal = false;

        }
};

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

int main() {

    TrieNode* root = new TrieNode('-');

    insertTrieNode(root, "love");
    insertTrieNode(root, "cater");
    insertTrieNode(root, "care");
    insertTrieNode(root, "com");
    insertTrieNode(root, "lover");
    insertTrieNode(root, "loved");
    insertTrieNode(root, "laod");
    insertTrieNode(root, "lov");
    insertTrieNode(root, "bat");
    insertTrieNode(root, "cat");
    insertTrieNode(root, "car");


    if(searchWord(root, "car") ) {
    cout <<"found " << endl;
    }

  else {
    cout <<"Not found " << endl;
  }
    return 0;
}