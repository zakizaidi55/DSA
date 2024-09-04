class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string>st;
        for(auto vec: obstacles) {
            string key = to_string(vec[0]) + "_" + to_string(vec[1]);
            st.insert(key);
        }

        int x = 0;
        int y = 0;

        int maxD = 0;

        // pointing to north
        pair<int, int>dir = {0,1};

        for(int i=0; i<comft 90 deg
                dir = {-dir.second, dir.first};
            } 
mands.size(); i++) {
            if(commands[i] == -2) {
                // turn le
            else if(commands[i] == -1){
                // turn right 90 deg
                dir = {dir.second, -dir.first};
            }

            else {
                // move to the dir
                for(int step=0; step<commands[i]; step++) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    string nextKey = to_string(newX) + "_" + to_string(newY);
                    if(st.find(nextKey) != st.end()) {
                        // key found
                        break;
                    } 

                    x = newX;
                    y = newY;
                }
            }

            maxD = max(maxD, x*x + y*y);
        }

        return maxD;
    }
};