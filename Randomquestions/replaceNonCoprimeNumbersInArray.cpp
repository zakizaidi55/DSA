class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>result;

        for(int num: nums) {
            while(!result.empty()) {
                int lastElement = result.back();
                int currElement = num;
                int GCD = gcd(lastElement, currElement);

                if(GCD == 1) {
                    // iska matlab GCD == 1 h toh yeh element bas add hoga
                    break;
                }
                // yha aagye iska matlab GCD greater than 1 aaya hai
                result.pop_back();
                long long mult = (long long)lastElement*currElement;
                num = mult/GCD;
            }

            result.push_back(num);
        }

        return result;
    }
};


