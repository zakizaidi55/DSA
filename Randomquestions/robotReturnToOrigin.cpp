class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;

        for(char&ch: moves) {
            if(ch == 'U')
                x++;
            
            if(ch == 'D')
                x--;
            
            if(ch == 'R')
                y++;
            
            if(ch == 'L')
                y--;
        }

        return x == 0 && y == 0;
    }
};


