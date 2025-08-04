class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int>mp;
        int result = INT_MIN;
        int i = 0;
        int j = 0;

        while(j < fruits.size()) {
            mp[fruits[j]]++;
            if(mp.size() <= 2) {
                result = max(result, j-i+1);
            }

            else {
                // it means ki 2 se zyada types k fruit aa gye
                // shrinking the window
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) {
                    mp.erase(fruits[i]);
                }
                i++;
            }
            j++;    
        }
        return result;
    }
};


