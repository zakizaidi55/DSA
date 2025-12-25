class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());

        int turn = 0;
        for(int i=0; i<k; i++) {
            ans += max(happiness[i]-turn, 0);
            turn++;
        }

        return ans;
    }
};


