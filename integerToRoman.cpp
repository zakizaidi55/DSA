class Solution {
public:
    string intToRoman(int num) {
        string romanSymbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

        string ans = "";

        for(int i=0; i<13; i++) {
            cout << "Inside for loop " << values[i]  << endl;
            while(num >= values[i]) {
                cout << "values[i] " << values[i] << endl;
                ans += romanSymbol[i];
                num -= values[i];
            }
        }

        return ans;
    }
};