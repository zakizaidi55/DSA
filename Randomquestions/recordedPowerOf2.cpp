class Solution {
public:
    vector<int>getCount(int n) {
        vector<int>count(10, 0);
        while(n > 0) {
            count[n%10]++;
            n = n/10;
        }

        return count;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> count = getCount(n);

        for(int i=0; i<=29; i++) {
            if(count == getCount(1 << i))
                return true;
        }

        return false;
    }
};


