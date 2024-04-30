class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<long, long>mp;
        mp[0] = 1;
        int cumXor = 0;
        long long result = 0;

        for(char ch: word) {
            int shift = ch - 'a';
            cumXor ^= (1 << shift);

            result += mp[cumXor];
            // all char even in count
            for(char ch='a' ; ch<='j'; ch++) {
                int shift1 = ch-'a';
                long long checkXor = (cumXor ^ (1 << shift1));
                result += mp[checkXor];
            }

            mp[cumXor]++;
        }

        return result;
    }
};