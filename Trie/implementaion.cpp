#include<iostream>
#include<vector>
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


void storeString(TrieNode* root, vector<string>&ans, string &input, string& prefix) {

  // base case
  if(root->isTerminal == true) {
    ans.push_back(prefix + input);
  }

  for(char ch='a'; ch<='z'; ch++) {
    int index = ch - 'a';
    TrieNode* next = root->children[index];
    if(next != NULL) {
      // child exist
      input.push_back(ch);

      // baaki recursion 
      storeString(next, ans, input, prefix);
      // backtrack
      input.pop_back();
    }
  }
}

void findPrefixString(TrieNode* root, string input, vector<string>&ans, string& prefix) {
  // base case
  if(input.length() == 0) {
    TrieNode* lastChar = root;
    storeString(lastChar, ans,input, prefix);
    return;
  }

  char ch = input[0];
  int index = ch - 'a';
  TrieNode* child;

  if(root->children[index] != NULL) {
    child = root->children[index];
  }
  else {
    return;
  }

  findPrefixString(child, input.substr(1) ,ans, prefix);
}


vector<vector<string> >getSuggestions(TrieNode* root, string input) {
  vector<vector<string> >output;
  string inputHelper = "";
  TrieNode* prev = root;
  for(int i=0; i<input.length(); i++) {
    char lastCh = input[i];
    int index = lastCh - 'a';
    TrieNode* curr = prev->children[index];

    if(curr == NULL) {
      break;
    }

    else {
      vector<string> downAns;
      inputHelper.push_back(lastCh);
      string dummy = "";
      storeString(curr, downAns,inputHelper,dummy);
      output.push_back(downAns);
      // catch
      prev = curr;
    }
  }

  return output;
}

int main() {

    TrieNode* root = new TrieNode('-');

    insertTrieNode(root, "love");
    insertTrieNode(root, "cater");
    insertTrieNode(root, "care");
    insertTrieNode(root, "com");
    insertTrieNode(root, "lover");
    insertTrieNode(root, "loved");
    insertTrieNode(root, "load");
    insertTrieNode(root, "lov");
    insertTrieNode(root, "bat");
    insertTrieNode(root, "cat");
    insertTrieNode(root, "car");

    // string input = "ca";
    


    // string prefix = input;
    // vector<string>ans;

    // findPrefixString(root, input, ans, prefix);

    // for(auto i:ans) {
    //   cout << i << " "; 
    // }

    vector<vector<string> > ans = getSuggestions(root, "loa");

    for(int i=0; i<ans.size(); i++) {
      cout << i << "->" ;
      for(auto str:ans[i]) {
        cout << str << ",";
      } cout << endl;
    }

    //if(searchWord(root, "car") ) {
    //   cout <<"found " << endl;
    // }

    // else {
    //   cout <<"Not found " << endl;
    // }


    return 0;
}