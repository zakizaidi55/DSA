class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int lastElement = n*n;

        unordered_map<int, int>mp;
        int a = -1;
        int b = -1;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                mp[grid[i][j]]++;
            }
        }

        for(int num = 1; num <= lastElement; num++) {
            if(!mp.count(num)) {
                //not found
                b = num;
            } 
            else if(mp[num] == 2) {
                //found twice
                a = num;
            }

        }

        return {a, b};
    }
};
