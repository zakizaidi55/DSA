class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int k1 = cost[0];
        int k2 = cost[1];
       
        for(int i = 2; i < cost.size(); ++i)  {
            int minOfTwo = cost[i] + min(k1, k2);
            k1 = k2;
            k2 = minOfTwo;
        }
        return min(k1,k2);
    }
};