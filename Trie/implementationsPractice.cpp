#include <iostream>
using namespace std;

class Trie {
  public:
    char value;
    Trie* children[26];
    bool isTerminal;
    
    Trie(char val) {
      this->value = val;
      
      for(int i=0; i<26; i++) {
        children[i] = NULL;
      }
      this->isTerminal = false;
    }
};

void insertWord(Trie* root, string word) {
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    Trie* child;
    int index =  ch - 'a';
    if(root->children[index] !=  NULL) {
        child = root->children[index];
    }

    else {
        child = new Trie(ch);
        root->children[index] = child;
    }

    insertWord(child, word.substr(1));
}

int main() {
  Trie *root = new Trie('-');
  return 0;
}