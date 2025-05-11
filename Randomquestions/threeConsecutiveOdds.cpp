class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() < 3) 
            return false;
        
        int i = 0;
        int j = 2;
        int threeOddCount = 0;
        
        for(int k=i; k<=j; k++) {
            if(arr[k] &1) {
                // odd number found 
                threeOddCount++;
            }
        }


        if(threeOddCount == 3) {
            return true;
        }
        j++;
        while(j < arr.size()) {

            if(arr[i] &1) {
                threeOddCount--;
            }

            i++;

            if(arr[j] &1) {
                // odd number
                threeOddCount++;
            }

            if(threeOddCount == 3) {
                return true;
            }

            j++;
        }

        return false;
    }
};


----------------------------------------------------------
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {

        if(arr.size() < 3)
            return false;
        int oddCount = 0;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i]&1)
                oddCount++;
            
            else
                oddCount = 0;
            
            if(oddCount == 3)
                return true;
        }

        return false;
    }
};


