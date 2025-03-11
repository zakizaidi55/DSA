class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>mp(3, 0);  //0->a, 1->b, 2->c    

        int n = s.size();

        int result = 0;
        int i = 0;
        int j = 0;

        while(j < n) {
            char ch = s[j];
            mp[ch - 'a']++;
            //catch->yha par while isliye use kara hai
            // aaacb -> isme 3 valid substring hai, or agr i ko if ke anday use karte toh we can only get one valid ans
            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0) {
                result += n-j;
                mp[s[i]-'a']--;
                i++;
            }

            j++;
        }

        return result;
    }
};

