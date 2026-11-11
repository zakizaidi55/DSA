class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // case1: cost1+cost2 < costBoth
        long long ans = 0;
        if(cost1 + cost2 <= costBoth) {
            ans = (1LL * need1*cost1) + (1LL * need2*cost2);
            return ans;
        }

        // case2: cost1+cost2 > costBoth
        int both = min(need1, need2);
        long long total = 1LL * both*costBoth;

        need1 -= both;
        need2 -= both;

        if(need1 > 0 ) {
            total += 1LL * need1 * min(costBoth, cost1);
        }

        if(need2 > 0) {
            total += 1LL * need2 * min(costBoth, cost2);
        }

        return total;
    }
};


