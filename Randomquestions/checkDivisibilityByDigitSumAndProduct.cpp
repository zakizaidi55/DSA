class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while(n > 0) {
            int digit = n%10;
            sum += digit;
            n /= 10;
        }

        return sum;
    }

    int getProd(int n) {
        int prod = 1;
        while(n > 0) {
            int digit = n%10;
            prod *= digit;
            n /= 10;
        }

        return prod;
    }

    bool checkDivisibility(int n) {
        if(n < 10)
            return false;
        
        int digitSum = getSum(n);
        int prod = getProd(n);

        int sum = digitSum + prod;
        return n%sum == 0 ? true : false;
    }
};


