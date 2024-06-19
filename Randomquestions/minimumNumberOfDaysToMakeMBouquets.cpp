class Solution {
public:
    bool canWeMakeMBouqeutWithDDays(vector<int>& bloomDay, int m, int k, int day) {
        int c = 0; // counter
        for(int i=0; i<bloomDay.size(); i++) {
            // check weather the ith flower is bloomed or not
            if(bloomDay[i] <= day) {
                c++;
            } 

            if(c == k) {
                //  i can make a bouqet
                m--;
                c = 0;
                if(m == 0)
                    break;
            }

            if(bloomDay[i] > day) {
                c = 0;
            } 
        }
        return m == 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        double requirement = (double)m*(double)k;
        if(bloomDay.size() < requirement) {
            return -1;
        }
        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = 0;
        int mid = (start+end)/2;
        while(start <= end) {
            int day = mid;
            if(canWeMakeMBouqeutWithDDays(bloomDay, m, k, day)) {
                ans = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
            mid = (start+end)/2;
        }

        return ans;
    }
};