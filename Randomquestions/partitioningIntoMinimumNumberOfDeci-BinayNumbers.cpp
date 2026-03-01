class Solution {
public:
    int minPartitions(string n) {
        int count = 0;
        while(true) {
            bool isChanged = false; 

            for(char&ch: n) {
                if(ch != '0') {
                    ch--;
                    isChanged = true;
                }
            }

            if(!isChanged) 
                break;
            
            count++;
        }
        
        return count;
    }
};


