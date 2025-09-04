class Solution {
public:
    int findClosest(int x, int y, int z) {
        int firstDiff = abs(z-x);
        int secondDiff = abs(z-y);

        if(firstDiff == secondDiff) 
            return 0;
        
        return firstDiff < secondDiff ? 1 : 2;
    }
};

