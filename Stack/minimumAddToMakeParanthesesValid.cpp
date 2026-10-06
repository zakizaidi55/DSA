class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBracket = 0;
        int closeBracket = 0;

        for(char ch: s) {
            if(ch == '(')
                openBracket++;
            
            else {
                if(openBracket > 0)
                    openBracket--;
                
                else
                    closeBracket++;
            }
        }

        return openBracket + closeBracket;
        // stack<char>st;
        // int closeBracketCount = 0;

        // for(char&ch: s) {
        //     if(ch == '(')
        //         st.push('(');
            
        //     else if(!st.empty() && st.top() == '(') 
        //         st.pop();
            
        //     else if(st.empty() && ch == ')') 
        //         closeBracketCount++;
        // }

        // return closeBracketCount + st.size();
    }
};


