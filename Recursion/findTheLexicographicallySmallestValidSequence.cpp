class Solution {
public:
    bool solveUsingRec(string&word1, string&word2, int i, int j, vector<int>&paths, bool hasReplaced) {
        if(j == word2.size())
            return true;
        
        if(word1.size() - i < word2.size() - j) // iska matlab agar word1 m character reh gye toh false return karna hai
            return false;

        if(word1[i] == word2[j]) {
            paths.push_back(i);
            return solveUsingRec(word1, word2, i+1, j+1, paths, hasReplaced);
        }
        int pathLen = paths.size();
        // dono character different hai
        // mere pass 2 choices hai
        // choice1: m ith char ko jth character k equal kardu
        if(!hasReplaced) {
            paths.push_back(i);


            if(solveUsingRec(word1, word2, i+1, j+1, paths, true)) 
                return true;
            
            // agar yha se false aata hai toh jo humne character add kara tha usko remove karna hoga
            // backtrack
            paths.resize(pathLen);
        }
        // choice2: m ith char ko skip karke aage chala jau 
        while(i < word1.size() && word1[i] != word2[j])
            i++;
        
        return solveUsingRec(word1, word2, i, j, paths, hasReplaced);
        // but m ek baar hi character ko same kar sakta hu, or lexicographically smallest vector banan hai

    }
    vector<int> validSequence(string word1, string word2) {
        vector<int>paths;
        bool hasReplaced = false;
        if(!solveUsingRec(word1, word2, 0, 0, paths, hasReplaced))
            return {};
    
        return paths;
    }
};


