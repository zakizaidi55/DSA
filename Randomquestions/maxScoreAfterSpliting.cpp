class Solution {
public:
    int maxScore(string s) {


        int ans = INT_MIN;
        int ones = 0;
        int zeros = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '1')
                ones++;
        }

        // now we have one count store in the variable
        //ab hum left to right iterate karege or dekhege ki agr left m humko 1 milta hai toh
        //usko ones-- karege kyuki wo 1 left part m include hogya hai

        for(int i=0; i<s.size()-1; i++) {
            if(s[i] == '1')
                ones--;
            
            else
                zeros++;
            

            ans = max(ans, ones+zeros);
        }

        return ans;



        //---------------------------------------------Method2---------------------------------------------
        // int ans = 0;
        // for(int i=0; i<s.size()-1; i++) {
        //     int curr = 0;

        //     for(int j=0; j<=i; j++) {
        //         if(s[j] == '0') 
        //             curr++;
        //     }

        //     for(int j=i+1; j<s.size(); j++) {
        //         if(s[j] == '1')
        //             curr++;
        //     }

        //     ans = max(ans, curr);
        // }

        // return ans;
    }
};