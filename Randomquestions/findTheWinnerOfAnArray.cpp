class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxi = arr[0];
        int cnt = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (maxi < arr[i]) {
                maxi = arr[i];
                cnt = 1;
            }
            else {
                cnt++;
            }

            if (cnt == k) {
                break;
            }
        }
        return maxi;
    }
};