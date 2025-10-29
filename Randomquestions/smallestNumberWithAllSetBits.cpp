class Solution {
public:
    bool checkAllBitsSet(int result) {
        if((result&(result+1)) == 0)
            return true;
        
        return false;
    }
    int smallestNumber(int n) {
        int result = n;
        while(!checkAllBitsSet(result)) {
            result++;
        }

        return result;
    }
};


