class Solution {
public:
    const int M = 1e9+7;
    int concatenatedBinary(int n) {
        long result = 0;
        int digit = 0; // represent kar rha h ki humko kitni bits chahiye next number k liye
        for(int num=1; num<=n; num++) {
            if((num&(num-1)) == 0 ) {
                // this is power of 2
                digit++;
            }

            result = ((result << digit) % M + num) % M;
        }

        return result;
    }
}

//////////////Approach2/////////////////////

class Solution {
public:
    const int M = 1e9+7;
    int concatenatedBinary(int n) {
        long result = 0;
        // int digit = 0; // represent kar rha h ki humko kitni bits chahiye next number k liye
        for(int num=1; num<=n; num++) {
            int digit = log2(num) + 1;

            result = ((result << digit) % M + num) % M;
        }

        return result;
    }
};


