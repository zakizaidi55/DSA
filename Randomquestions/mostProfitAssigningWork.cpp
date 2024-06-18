class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int> >v;
        for(int i=0; i<difficulty.size(); i++) {
            v.push_back({profit[i], difficulty[i]});
        }

        sort(v.begin(), v.end(), greater<pair<int, int> >());
        sort(worker.begin(), worker.end(), greater<int>());

        int i = 0; //v index
        int j = 0; //worker index

        int ans = 0;

        while(i < v.size() && j < worker.size()) {
            if(worker[j] >= v[i].second) {
                ans += v[i].first;
                j++;
            } else {
                i++;
            }
        }   

        return ans;
    }
};