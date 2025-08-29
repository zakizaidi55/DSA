class Solution {
public:
    long long flowerGame(int n, int m) {
        long long odd_n_number = (n+1)/2;
        long long even_n_number = n/2;

        long long odd_m_number = (m+1)/2;
        long long even_m_number = m/2;
        
        long long ans = (odd_n_number * even_m_number) + (odd_m_number * even_n_number);

        return ans;
    }
};
