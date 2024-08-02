class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // vector<int>temp(2*n);
        // for(int i=0; i<2*n; i++) {
        //     temp[i] = nums[i%n];
        // }

        int totalOnes = accumulate(nums.begin(), nums.end(), 0);

        int i = 0;
        int j = 0;

        int currOne = 0;
        int maxCount = 0;

        while(j < 2*n) {
            if(nums[j%n] == 1)
                currOne++;
            
            if(j - i + 1 > totalOnes) {
                // window ka size bada ho gya
                currOne -= nums[i%n];
                i++;
            }
            maxCount = max(maxCount, currOne); // humne nikala kis window me sabse zyda one h toh utne kam swap lagege
            j++;
        }     
        
        return totalOnes - maxCount;
    }
    
};