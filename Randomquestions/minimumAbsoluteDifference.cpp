class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int> >ans;
        int maxDiff = INT_MAX;
        for(int i=1; i<arr.size(); i++) {
            int diff = arr[i] - arr[i-1];
            maxDiff = min(diff, maxDiff);
        }

        for(int i=1; i<arr.size(); i++) {
            if(arr[i] - arr[i-1] == maxDiff) {
                ans.push_back({arr[i-1], arr[i]});
            }
        }

        return ans;
    }
};


