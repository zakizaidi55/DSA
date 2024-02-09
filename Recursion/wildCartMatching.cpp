class Solution {
public:
    bool solveUsingRecursion(string &s, string &p, int si, int pi) {
        if(si == s.size() && pi == p.length())
            return true;
        
        if(si == s.size() && pi <= p.length()) {
            while(pi < p.size()) {
                if(p[pi] != '*')
                    return false;
                pi++;
            }

            return true;
        }
            

        // single character matching
        if(s[si] == p[pi] || '?' == p[pi]) {
            // matching
            return solveUsingRecursion(s, p, si+1, pi+1);
        }

        if(p[pi] == '*') {
            // treat '*' as empty or null
            bool caseA = solveUsingRecursion(s, p, si, pi+1);
            // let * consume one character
            bool caseB = solveUsingRecursion(s, p, si+1, pi);

            return caseA || caseB;
        }

        // character doesnt match
        return false;

    }
    bool isMatch(string s, string p) {
       int si = 0;
       int pi = 0;
        return solveUsingRecursion(s, p, si, pi);
    }
};
