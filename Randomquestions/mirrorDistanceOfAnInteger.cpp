class Solution {
public:
    int reverse(int n) {
        int reverseNum = 0;
        while(n > 0) {
            int digit = n%10;
            reverseNum = reverseNum*10 + digit; 
            n /= 10;
        }

        return reverseNum;
    }
    int mirrorDistance(int n) {
        int reverseNum = reverse(n);

        return abs(n - reverseNum);
    }
};


