class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int>mp;
        for(int i=0; i<matches.size(); i++) {
            int lost = matches[i][1];

            mp[lost]++;
        }

        vector<int>oneWinner;
        vector<int>losser;

        for(int i=0; i<matches.size(); i++) {
            int winner = matches[i][0];
            int lost = matches[i][1];

            if(mp.find(winner) == mp.end()) {
                oneWinner.push_back(winner);
                mp[winner] = INT_MIN;
            }

            if(mp[lost] == 1) {
                losser.push_back(lost);
            }
        }

        sort(oneWinner.begin(), oneWinner.end());
        sort(losser.begin(), losser.end());

        return {oneWinner, losser};
    }
};