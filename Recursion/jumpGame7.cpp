class Solution {
public: 
    // bool solveUsingRec(string&s, int minJump, int maxJump, int index) {
    //     if(index == s.size()-1)
    //         return true;
        
    //     for(int jump=minJump; jump<=maxJump; jump++) {
    //         if(index+jump >= s.size())
    //             break;
            
    //         if(s[index+jump] == '0') {
    //             if(solveUsingRec(s, minJump, maxJump, index+jump)) 
    //                 return true;
    //         }
    //     }

    //     return false;

    // }

    bool solveUsingMem(string&s, int minJump, int maxJump, int index, vector<int>&dp) {
        if(index == s.size()-1)
            return true;
        
        if(dp[index] != -1)
            return dp[index];

        for(int jump=minJump; jump<=maxJump; jump++) {
            int j = index+jump;
            if(j >= s.size())
                break;
            
            if(s[j] == '0') {
                if(solveUsingMem(s, minJump, maxJump, j, dp)) 
                    return dp[index] = true;
            }
        }

        return dp[index] = false;

    }

    bool solveUsingTab(string&s, int minJump, int maxJump) {
        vector<int>dp(s.size(), false);
        dp[s.size()-1] = true;

        for(int i=s.size()-2; i>=0; i--) {
            for(int jump=minJump; jump<=maxJump; jump++) {
                int j = i+jump;
                if(j >= s.size())
                    break;
                
                if(s[j] == '0') {
                    if(dp[j])  {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[0];
    }


    bool canReach(string s, int minJump, int maxJump) {
        int index = 0;
        // vector<int>dp(s.size()+1, -1);
        // return solveUsingRec(s, minJump, maxJump, index);
        // return solveUsingMem(s, minJump, maxJump, index, dp);
        // return solveUsingTab(s, minJump, maxJump);
        int n = s.length();

        vector<int> t(n, 0);


        t[0] = 1;
        int count = 0;

        for(int j=1; j<=n-1; j++) {
            if(j - minJump >= 0) {
                count += t[j - minJump];
            }

            if(j - maxJump - 1 >= 0) {
                count -= t[j - maxJump - 1];
            }

            if(count > 0 && s[j] == '0') {
                t[j] = 1;
            }
        }

        return t[n-1] > 0;
    }
};


