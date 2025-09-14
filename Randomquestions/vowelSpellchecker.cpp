class Solution {
public:
    string toLower(string&s) {
        string result = s;
        for(auto&ch:result) 
            ch = tolower(ch);

        return result;
    }

    string replaceVowel(string&s) {
        string result = s;
        for(auto&ch:result) {
           if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') 
                ch = '*';
        }
        return result;
    }

    string checkForMatch(string&query, unordered_set<string>&exactWord, unordered_map<string, string>&caseMp, unordered_map<string, string>&vowelMp) {
        if(exactWord.count(query))
            return query;
        
        // check for case sensitive
        string lowerCase = toLower(query);
        if(caseMp.count(lowerCase)) 
            return caseMp[lowerCase];
        
        // check for vowel mismatch
        string vowelCase = replaceVowel(lowerCase);
        if(vowelMp.count(vowelCase))
            return vowelMp[vowelCase];
        

        return "";
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string>exactWord(wordlist.begin(), wordlist.end());
        unordered_map<string, string>caseMp;
        unordered_map<string, string>vowelMp;

        for(auto word:wordlist) {
            string lowerCase = toLower(word);
            if(caseMp.find(lowerCase) == caseMp.end()) {
                caseMp[lowerCase] = word;
            }

            string vowelCase = replaceVowel(lowerCase);
            if(vowelMp.find(vowelCase) == vowelMp.end()) {
                vowelMp[vowelCase] = word;
            }
        }

        vector<string>res;
        for(string&query: queries) {
            res.push_back(checkForMatch(query, exactWord, caseMp, vowelMp));
        }

        return res;
    }
};


