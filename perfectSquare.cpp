class Solution {
public:
    int numSquaresHelper(int n) {
        // base case
        if(n == 0) {
            return 1;
        }

        if(n < 0)
            return 0;

        int i = 1;
        int end = sqrt(n);
        int ans = INT_MAX;

        while(i <= end) {
            int perfectSq = i*i;
            int numberOfPerfectSquare = 1 + numSquaresHelper(n - perfectSq);
            if(numberOfPerfectSquare < ans) {
                ans = numberOfPerfectSquare;
            }

            i++;
        }
        return ans;
    }
    int numSquares(int n) {

        return numSquaresHelper(n) - 1;
    }
};