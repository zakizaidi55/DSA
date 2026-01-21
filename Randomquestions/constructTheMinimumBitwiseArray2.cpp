class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;
        for(int&num: nums) {
            if(num == 2) {
                result.push_back(-1);
                continue;
            }
            bool found = false;
            for(int j=0; j<32; j++) {
                if((num & (1<<j)) > 0) {
                    continue;
                }

                int prev = j-1;
                int x = (num ^ (1 << prev));
                result.push_back(x);
                found = true;
                break;
            }
            if(!found) 
                result.push_back(-1);
        }
        return result;
    }
};


