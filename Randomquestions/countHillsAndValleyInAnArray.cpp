class Solution {
public:
    int countHillValley(vector<int>& nums) {

        
        int i = 0;
        int j = i+1;
        int count = 0;
        while(j < nums.size()-1) {
            if((nums[i] < nums[j] && nums[j] > nums[j+1]) || (nums[i] > nums[j] && nums[j] < nums[j+1])) {
                count++;
                i = j;
            }
            
            j++;
        }

        return count;

        // =====================TC =O(n) and SC = O(n) =============================
        // vector<int>newNums;
        // newNums.push_back(nums[0]);
        // for(int i=1; i<nums.size(); i++) {
        //     if(nums[i] != nums[i-1]) {
        //         newNums.push_back(nums[i]);
        //     }
        // }

        // // now I have new nums with no duplicates
        // int count = 0;

        // for(int i=1; i<newNums.size()-1; i++) {
        //     if((newNums[i] > newNums[i-1] && newNums[i] > newNums[i+1] ) || (newNums[i] < newNums[i-1] && newNums[i] < newNums[i+1]))
        //         count++;
        // }

        // return count;



    }
};


