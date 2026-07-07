class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0;      
        int sum = 0;
        string num = to_string(n);
        for(int i=0; i<num.size(); i++) {
            if(num[i] != '0') {
                int digit = num[i] - '0';
                ans = ans*10+digit;
                sum += digit;
            }
        }

        return ans*sum;
    }
};


