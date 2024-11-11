class Solution {
public:
    void seive(vector<bool>&isPrime) {
        isPrime[0] = isPrime[1] = false;

        for(int i=2; i<1000; i++) {
            if(isPrime[i]) {
                for(int j=i*i; j<1000; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<bool>isPrime(1000, true);

        seive(isPrime);

        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) 
                continue;

            // nums[i] > nums[i+1]
            // decrese nums[i] atleast less than nums[i+1]

            // check prime number less than nums[i]
            for(int p=2; p<nums[i]; p++) {
                if(!isPrime[p]) 
                    continue;
                
                if(nums[i] - p < nums[i+1]) {
                    nums[i] -= p;
                    break;
                }
            }


            if(nums[i] >= nums[i+1])
                return false;
            
        }


        return true;
    }
};