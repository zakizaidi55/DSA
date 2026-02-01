class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int firstMin = nums[0];
        int secondMin = INT_MAX;
        int thirdMin = INT_MAX;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] < secondMin ) {
                thirdMin = secondMin; //catch-> important to keep the track pichle wala min element ka, yha galti kari thi
                secondMin = nums[i];
            }

            else if(nums[i] < thirdMin) {
                thirdMin = nums[i];
            }
        }

        return firstMin + secondMin + thirdMin;
    }
};


