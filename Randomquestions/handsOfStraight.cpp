class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if((hand.size()%groupSize) != 0) 
            return false;
        
        map<int, int>mp;
        for(auto &handNumber: hand) {
            mp[handNumber]++;
        }

        while(!mp.empty()) {
            int curr = mp.begin()->first;
            // cout << "curr " << curr << endl;
            for(int i=0; i<groupSize; i++) {
                if(mp[curr+i] == 0) {
                    return false;
                }
                // cout << "mp[curr+i] " << mp[curr+i] << endl; 
                mp[curr+i]--;

                if(mp[curr+i] < 1) {
                    mp.erase(curr+i);
                }
            }
        }
        return true;
    }
};