class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {  
        for(int i=0; i<fruits.size(); i++) {
            for(int j=0; j<baskets.size(); j++) {
                if(baskets[j] >= fruits[i]) {
                    baskets[j] = -1;
                    break;
                }
            }
        }      

        int remainingCount = 0;
        for(int j=0; j<baskets.size(); j++) {
            if(baskets[j] != -1) 
                remainingCount++;
        }

        return remainingCount;
    }
};


