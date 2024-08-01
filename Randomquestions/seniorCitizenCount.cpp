class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniorCount = 0;
        for(auto &info: details) {
            string subPart = info.substr(11,2);
            int subPartInt = stoi(subPart);
            if(subPartInt > 60) {
                seniorCount++;
            }
        }
        return seniorCount;
    }
};