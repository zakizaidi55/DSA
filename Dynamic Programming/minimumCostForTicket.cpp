class Solution {
public:
    int minCostTicketsHelper(vector<int>& days, vector<int>& costs, int i) {
        // base case
        if(i >= days.size())
            return 0;

        // sol for one case
        // one day pass
        int cost1 = costs[0] + minCostTicketsHelper(days, costs, i+1);

        // 7 day pass
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while(j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost7 = costs[1] + minCostTicketsHelper(days, costs, j);


        // 30 day pass
        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost30 = costs[2] + minCostTicketsHelper(days, costs, j);

        
        return min(cost1, min(cost7,cost30));
    }


    int solveUsingMem(vector<int>& days, vector<int>& costs, int i, vector<int>&dp) {
        // base case
        if(i >= days.size())
            return 0;

        if(dp[i] != -1)
            return dp[i];
        // sol for one case
        // one day pass
        int cost1 = costs[0] + solveUsingMem(days, costs, i+1, dp);

        // 7 day pass
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while(j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost7 = costs[1] + solveUsingMem(days, costs, j, dp);


        // 30 day pass
        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost30 = costs[2] + solveUsingMem(days, costs, j, dp);

        
        dp[i] = min(cost1, min(cost7,cost30));

        return dp[i];
    }


    int solveUsingTab(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1, -1);
        dp[days.size()] = 0;
        for(int i=days.size()-1; i>=0; i--) {
            // sol for one case
            // one day pass
            int cost1 = costs[0] + dp[i+1];

            // 7 day pass
            int passEndDay = days[i] + 7 - 1;
            int j = i;
            while(j < days.size() && days[j] <= passEndDay) {
                j++;
            }
            int cost7 = costs[1] + dp[j];


            // 30 day pass
            passEndDay = days[i] + 30 - 1;
            j = i;
            while(j < days.size() && days[j] <= passEndDay) {
                j++;
            }
            int cost30 = costs[2] + dp[j];

            
            dp[i] = min(cost1, min(cost7,cost30));

        }

        return dp[0];
    }
    

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1, -1);
        // return minCostTicketsHelper(days, costs, 0);
        // return solveUsingMem(days, costs, 0, dp);
        return solveUsingTab(days, costs);
    }
};
