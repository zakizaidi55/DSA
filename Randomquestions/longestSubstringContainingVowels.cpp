class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string, int> mp;
        vector<int>vowelState(5, 0);

        string currState = "00000";
        mp[currState] = -1;

        int result = 0;

        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'a') {
                vowelState[0] = (vowelState[0] + 1) %2;
            }

            else if(s[i] == 'e') {
                vowelState[1] = (vowelState[1] + 1) %2;
            }

            else if(s[i] == 'i') {
                vowelState[2] = (vowelState[2] + 1) %2;
            }

            else if(s[i] == 'o') {
                vowelState[3] = (vowelState[3] + 1) %2;
            }

            else if(s[i] == 'u') {
                vowelState[4] = (vowelState[4] + 1) %2;
            }

            currState = "";

            for(int j=0; j<vowelState.size(); j++) {
                currState += to_string(vowelState[j]);
            }

            if(mp.find(currState) != mp.end()) {
                result = max(result, i-mp[currState]);
            }

            else {
                mp[currState] = i;
            }
        }

        return result;
    }
};