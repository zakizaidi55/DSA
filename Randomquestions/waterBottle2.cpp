class Solution {
public:
    int solveUsingRec(int numBottles, int numExchange) {
        if(numBottles < numExchange) {
            return 0;
        }

        return 1 + solveUsingRec(numBottles-numExchange+1, numExchange+1);

    }
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int recAns = solveUsingRec(numBottles, numExchange);
        return ans + recAns;
    }
};


