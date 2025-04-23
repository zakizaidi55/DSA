class Solution {
public:
    int convertToSingleDigit(int num) {
        int singleDigit = 0;
        while(num > 0) {
            int n = num%10;
            singleDigit += n;
            num = num/10;
        }

        return singleDigit;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int>mp;

        for(int i=1; i<=n; i++) {
            int digit = convertToSingleDigit(i);
            cout << digit << endl;
            mp[digit]++;
        }

        int count = 0;
        int maxi = 0;

        for(auto it:mp) {
            if(it.second > maxi) {
                count = 1;
                maxi = it.second;
            }

            else if(it.second == maxi) {
                count++;
            }
            
        }

        return count;
    }
};


