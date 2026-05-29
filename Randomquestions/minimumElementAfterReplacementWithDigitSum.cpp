class Solution {
public:
    int convertSingle(int num) {
        int result = 0;
        while(num > 0) {
            int digit = num%10;
            result = result + digit;
            num /= 10;
        }
        return result;
    }
    int minElement(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] >= 10) {
                int singleDigit = convertSingle(nums[i]);
                nums[i] = singleDigit;
            }
        }

        int minElement = INT_MAX;
        for(int i: nums) {
            minElement = min(i, minElement);
        }

        return minElement;
    }
};


