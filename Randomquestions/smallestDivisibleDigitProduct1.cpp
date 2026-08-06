class Solution {
public:
    bool isDivisible(int i, int t) {
        int product = 1;
        while(i > 0) {
            int digit = i%10;
            product = product * 1 * digit;
            i = i/10;
        }

        return product%t == 0;
    }
    int smallestNumber(int n, int t) {
        for(int i=n; i<=100; i++) {
            if(isDivisible(i, t)) 
                return i;
        }

        return 0;
    }
};



