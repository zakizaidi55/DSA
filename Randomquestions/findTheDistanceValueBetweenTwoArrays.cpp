class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;

        for(int i=0; i<arr1.size(); i++) {
            int j = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();

            if(j == 0) {
                // iska matlab mera pehla hi index just bada h arr1[i] se
                count += arr2[j] - arr1[i] > d;
            }

            else if(j == arr2.size()) {
                // iska matlab mera sare element chote h arr1[i] se
                count += arr1[i] - arr2[arr2.size()-1] > d;
            }

            else {
                // yha par aaya toh matlab kahi bich m aaya hu
                count += (arr2[j] - arr1[i] > d) && (arr1[i] - arr2[j-1] > d);
            }
        }

        return count;
    }
};
