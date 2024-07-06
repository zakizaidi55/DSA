class Solution {
public:
    int passThePillow(int n, int time) {
        bool flag = true; // means left to right
        int standCount = 1;
        while(time--) {
            if(flag) {
                standCount++;
                if(standCount == n) 
                    flag = !flag;
                
            }

            else {
                standCount--;
                if(standCount == 1) 
                    flag = !flag;
            }
        }

        return standCount;

    }
};