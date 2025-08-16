class Solution {
public:
    int maximum69Number (int num) {
        bool change = false;
        int n = num;
        vector<int>digits;
        while(n > 0) {
            int lastDigit = n%10;
            digits.push_back(lastDigit);
            n = n/10;
        }

        for(int i=digits.size()-1; i>=0; i--) {
            if(digits[i] == 6 && change == false) {
                digits[i] = 9;
                change = true;
                break;
            } 
        }
        int ans = 0;
        for(int i=digits.size()-1; i>=0; i--) {
            ans = ans*10 + digits[i];
        }

        return ans;
    }
};


