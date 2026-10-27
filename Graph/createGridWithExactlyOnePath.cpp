class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string topRow(n, '.'); // first wali row m, hum sare '.' dal dege
        string remaining = string(n-1, '#') + '.'; // bachi hui rows ke last index par hum '.' dalege

        vector<string> result;
        result.push_back(topRow);

        for(int i=1; i<m; i++) {
            result.push_back(remaining);
        }

        return result;
    }
};


