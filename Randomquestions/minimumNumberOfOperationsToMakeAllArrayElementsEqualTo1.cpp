class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;
        int oneCount = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 1) 
                oneCount++;
        }

        if(oneCount > 0) 
            return (nums.size()-oneCount);

        int minStep = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            int GCD = nums[i];
            for(int j=i+1; j<nums.size(); j++) {
                GCD = gcd(GCD, nums[j]);
                if(GCD == 1) { 
                    // agr humko 1 mil gya toh uska operations count karlege ki kitne operations lage
                    minStep = min(minStep, j-i);
                    break;
                }
            }
        }

        if(minStep == INT_MAX)
            return -1;
        
        return (minStep + nums.size()-1);
    }
};


