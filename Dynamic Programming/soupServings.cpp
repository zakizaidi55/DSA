class Solution {
public:
    vector<pair<double, double> >prob = {{100.0, 0.0}, {75.0, 25.0}, {50.0,50.0}, {25.0, 75.0}};
    double solveUsingRec(double a, double b) {
        if(a <= 0.0 && b <= 0.0) 
            return 0.5;

        if(a <= 0.0)
            return 1.0;
        
        if(b <= 0)
            return 0.0;
        double probabilty = 0;
        for(auto&p: prob) {
            double aTaken = p.first;
            double bTaken = p.second;

            probabilty += solveUsingRec( a-aTaken, b-bTaken);
        } 

        return probabilty*0.25;
    }

    double solveUsingMem(double a, double b, vector<vector<double> >&dp) {
        if(a <= 0.0 && b <= 0.0) 
            return 0.5;

        if(a <= 0.0)
            return 1.0;
        
        if(b <= 0)
            return 0.0;

        if(dp[a][b] != -1.0)
            return dp[a][b];
        double probabilty = 0;
        for(auto&p: prob) {
            double aTaken = p.first;
            double bTaken = p.second;

            probabilty += solveUsingMem( a-aTaken, b-bTaken, dp);
        } 

        dp[a][b] = probabilty*0.25;
        return dp[a][b];
    }
    double soupServings(int n) {
        if(n >= 5000)
            return 1.0;
        double a = n;
        double b = n;
        vector<vector<double> >dp(n+1, vector<double>(n+1, -1.0));
        // return solveUsingRec( a, b);
        return solveUsingMem(a, b, dp);
    }
};


