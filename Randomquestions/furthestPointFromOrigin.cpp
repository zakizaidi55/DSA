
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0;
        int right = 0;
        int dash = 0;

        for(char&ch: moves) {
            if(ch == 'L')
                left++;
            
            else if(ch == 'R')
                right++;
            
            else
                dash++;
        }

        // if(left > right) 
        //     left += dash;
        

        // else
        //     right += dash;
        
        // return abs(right - left) ;

        return abs(right - left) + dash;
    }
};


