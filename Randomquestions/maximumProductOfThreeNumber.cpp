class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int firstNumber = INT_MIN;
        int secondNumber = INT_MIN;
        int thirdNumber = INT_MIN;
        int firstSmall = 0;
        int secondSmall = 0;

        for(int num: nums) {
            if(num > firstNumber) {
                thirdNumber = secondNumber;
                secondNumber = firstNumber;
                firstNumber = num;
            }

            else if(num > secondNumber) {
                thirdNumber = secondNumber;
                secondNumber = num;
            }

            else if(num > thirdNumber) {
                thirdNumber = num;
            }

            if(num < firstSmall) {
                secondSmall = firstSmall;
                firstSmall = num;
            }

            else if(num < secondSmall ) {
                secondSmall = num;
            }
        }

        return max((firstNumber * secondNumber * thirdNumber), (firstNumber * firstSmall * secondSmall));
    }
};


