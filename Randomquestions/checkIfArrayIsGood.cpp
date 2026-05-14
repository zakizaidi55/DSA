class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int, int>freq;
        int maxElement = INT_MIN;

        bool isDouble = false;
        for(int i: nums) {
            freq[i]++;

            if(freq[i] > 1) {

                if(isDouble)
                    return false;
                
                isDouble = true;
            }
            
            maxElement = max(maxElement, i);
        }

        if(nums.size() != maxElement + 1)
            return false;
        
        if(freq[maxElement] == 2)
            return true;
        

        return false;
    }
};


