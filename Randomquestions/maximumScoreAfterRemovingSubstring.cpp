class Solution {
public:
    string remove(string&s, string&matchString) {
        stack<char>st;

        for(char&ch: s) {
            if(!st.empty() && st.top() == matchString[0] && ch == matchString[1]) 
                st.pop();
            else
                st.push(ch);
        }

        string temp = "";
        while(!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());
        return temp;

    }
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int score = 0;
        string maxString = (x > y) ? "ab" : "ba";
        string minString = (x <= y) ? "ab" : "ba";

        // remove maximum characters from string in first pass and it will return temp string
        string tempStringFirst = remove(s, maxString);
        int tempStringFirstLength = tempStringFirst.length();
        int charRemoved = n - tempStringFirstLength; 

        score += (charRemoved/2) * max(x, y);

        // remove minimum characters from string in second pass
        string tempStringSecond = remove(tempStringFirst, minString);
        int tempStringSecondLength = tempStringSecond.length();
        // ab hmare pas string ki length hogi tempStringFirstLength, kyuki n m se max char nikal gye h
        charRemoved = tempStringFirstLength - tempStringSecondLength;

        score += (charRemoved/2) * min(x, y);

        return score;
    }
};


