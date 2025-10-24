class Solution {
public:
    bool isBalanced(int num) {
        vector<int>count(10);
        while(num) {
            int digit = num%10;
            count[digit]++;
            num = num/10;
        }

        for(int i=0; i<10; i++) {
            if(count[i] != 0 && count[i] != i)
                return false;
        }

        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int num=n+1; num<=1224444; num++) {
            if(isBalanced(num)) 
                return num;
        }

        return 0;
    }
};


