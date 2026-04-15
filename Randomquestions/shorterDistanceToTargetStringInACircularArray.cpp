class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;

        for(int i=0; i<n; i++) {
            if(words[i] == target) {
                int straightDist = abs(i - startIndex);
                int circularDist = abs(n-straightDist);

                ans = min(ans, min(straightDist, circularDist));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
