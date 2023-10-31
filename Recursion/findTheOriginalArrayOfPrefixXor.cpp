class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        for (int i = pref.size() - 1; i >= 1; i--) {
            pref[i] = pref[i] ^ pref[i - 1];
            cout << pref[i] << endl;
        }
        return pref;
    }
};