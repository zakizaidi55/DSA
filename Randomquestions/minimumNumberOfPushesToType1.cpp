class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int, int>mp;
        int assignKey = 2;
        int result = 0;
        for(char&ch: word) {
            if(assignKey > 9) {
                assignKey = 2;
            }
            mp[assignKey]++;
            result += mp[assignKey];
            assignKey++;
        }
        return result;
    }
};


