class Solution {
public:
    int maxProduct(int n) {
        int largestNumber = 0;
        int secondLargestNumber = 0;

        while(n > 0) {
            int digit = n % 10;
            if(digit > largestNumber) {
                secondLargestNumber = largestNumber;
                largestNumber = digit;
            }

            else if(digit > secondLargestNumber) {
                secondLargestNumber = digit;
            }

            n = n/10;
        }

        return secondLargestNumber * largestNumber;
    }
};


