class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string>words;
        unordered_map<char, bool>brokenWord;
        int i = 0;
        int j = 0;

        while(j < text.length()) {
            if(text[j] == ' ') {
                string temp = text.substr(i, j-i);
                words.push_back(temp);
                i = j+1;
            }
            j++;
        }

        string temp = text.substr(i, j-i+1);
        words.push_back(temp);
        int totalWordsTyped = words.size();
        for(int i=0; i<brokenLetters.size(); i++) {
            brokenWord[brokenLetters[i]] = true;
        }

        for(string&str: words) {
            for(auto ch: str) {
                cout << ch << endl;
                if(brokenWord.find(ch) != brokenWord.end()) {
                    totalWordsTyped--;
                    break;
                }
            }
        }

        return totalWordsTyped;
    }
};


