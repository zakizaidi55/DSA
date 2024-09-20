class Solution {
public:
    vector<int>solveUsingRec(string s) {
        vector<int>result;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int>leftRes = solveUsingRec(s.substr(0,i));
                vector<int>rightRes = solveUsingRec(s.substr(i+1));


                for(int x: leftRes) {
                    for(int y: rightRes) {
                        if(s[i] == '+') {
                            result.push_back(x+y);
                        }

                        if(s[i] == '-') {
                            result.push_back(x-y);
                        }

                        if(s[i] == '*') {
                            result.push_back(x*y);
                        }
                    }
                } 
            }
        }

        if(result.size() == 0) {
            result.push_back(stoi(s));
        }

        return result;
    }   
    vector<int> diffWaysToCompute(string expression) {
        return solveUsingRec(expression);
    }
};