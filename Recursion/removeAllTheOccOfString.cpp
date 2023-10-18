class Solution {
public:

    void removeOccRe(string& s, string& part) {
        int found = s.find(part);
        // part string has been found
        if(found != string::npos) {
            // removing
            string leftPart = s.substr(0, found);
            string rightPart = s.substr(found+part.size(), s.size());
            s = leftPart + rightPart;

            removeOccRe(s, part);
        }

        else {
            // it is the base case
            // all the occurence of the part has been removed from the string
            return;
        }
    }
    string removeOccurrences(string s, string part) {
        removeOccRe(s, part);
        return s;

    }
};