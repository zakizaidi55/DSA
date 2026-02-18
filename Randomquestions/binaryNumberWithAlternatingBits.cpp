class Solution {
public:
    bool hasAlternatingBits(int n) {
        int currBit = n&1;
        n = n >> 1;

        while(n > 0) {
            if(currBit == (n&1))
                return false;
            
            currBit = n&1;
            n = n >> 1;
        }

        return true;
    }
};


