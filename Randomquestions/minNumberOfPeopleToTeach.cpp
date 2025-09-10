class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int>sadUser;
        for(auto frnd: friendships) {
            int u = frnd[0] - 1;
            int v = frnd[1] - 1;

            unordered_set<int>lang(begin(languages[u]), end(languages[u]));
            bool canTalk = false;
            for(int l: languages[v]) {
                if(lang.count(l)) {
                    canTalk = true;
                    break;
                }
            }

            if(!canTalk) {
                sadUser.insert(u);
                sadUser.insert(v);
            }
        }

        // find max knows among sad users
        unordered_map<int, int>langKnown;
        int mostLanguageKnown = 0;
        for(int user: sadUser) {
            for(int lang:languages[user]) {
                langKnown[lang]++;
                mostLanguageKnown = max(mostLanguageKnown, langKnown[lang]);
            }
        }

        return sadUser.size() - mostLanguageKnown;
    }
};


