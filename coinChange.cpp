class Solution {
public:
    int solve(vector<int>& coins, int amount) {
        // base case
        if(amount == 0)
            return 0;
        
        int ans = INT_MAX;
        int mini = INT_MAX;

        for(int i=0; i<coins.size(); i++) {
            int currCoin = coins[i];

            // we use the current coin only if the amount > currCoin
            if(currCoin <= amount) {
                int recAns = solve(coins, amount - currCoin);
                if(recAns != INT_MAX)
                    ans = 1 + recAns; 
            }
            mini = min(ans, mini);
        }

        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);

        if(ans == INT_MAX) 
            return -1;
       

       return ans;
    }
};