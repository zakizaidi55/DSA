class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        // yeh btayega ki i wala loop kha tak chalna h, or phr hum usko piche karte rahege
        for(int size=nums.size()-1; size>=1; size--) {    
            for(int i=0; i<size; i++) {
                nums[i] = (nums[i] + nums[i+1])%10;
            }
        }

        return nums[0];
        
        // while(nums.size() > 1) {
        //     vector<int>newNums;
        //     for(int i=0; i<nums.size()-1; i++) {
        //         newNums.push_back((nums[i]+nums[i+1])%10);
        //     }
        //     nums = newNums;
        //     move(newNums);
        // }

        // return nums[0];
    }
};


