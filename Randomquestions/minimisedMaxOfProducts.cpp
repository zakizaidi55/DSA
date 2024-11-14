class Solution {
public:
    bool posibleToDistribute(int x, vector<int>&quantities, int n) {
        for(int &products: quantities) {
            n -= (products+x-1)/x;//ceil(products/x);

            if(n < 0)
                return false;
        }

        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int shops = quantities.size();
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());

        int result = 0;


        while(left <= right) {
            int mid = left + (right-left)/2;
            if(posibleToDistribute(mid, quantities, n)) {
                result = mid;
                right = mid-1;
            }

            else {
                left = mid+1;
            }
        }

        return result;
    }
};