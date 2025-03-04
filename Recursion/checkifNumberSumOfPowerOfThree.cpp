class Solution {
public:
    int solve(int n, int p) {
        if(n == 0) {
            return true;
        }

        if(pow(3, p) > n) {
            return false;
        }

        //use the 'p' Power
        bool takeP = solve(n - pow(3, p), p+1);

        //not use the 'p' Power
        bool notTakeP = solve(n, p+1);

        return takeP || notTakeP;
    }

    bool checkPowersOfThree(int n) {
        return solve(n, 0);
    }
};
