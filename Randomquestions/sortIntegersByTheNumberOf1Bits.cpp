class Solution {
public:
    static bool comp(int&a, int&b) {
        int first = __builtin_popcount(a);
        int second = __builtin_popcount(b);

        if(first == second)
            return a < b;
        return first < second;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);

        return arr;
    }
};


