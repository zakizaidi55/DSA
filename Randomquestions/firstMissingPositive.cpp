class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool>mp;
        int maxi = *max_element(nums.begin(), nums.end());
        for(auto& num: nums) {
            mp[num] = true;
        }

        // check for the first positive missing number
        for(int i=1; i<maxi; i++) {
            if(mp.find(i) == mp.end()) {
                return i;
            }
        }

        // if all the integers are present in the map then return maxi+1;

        return maxi < 0 ? 1 : maxi+1;

    }
};


// ==================================Method2=================================
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(0);
        cout << "N " << n << endl; 
        for(int i=0; i<n; i++) {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]]) {
                swap(nums[i] ,nums[nums[i]]);
                for(auto num: nums) {
                    cout << num <<  " ";
                } cout << endl;
            }
            
        }

        

        for(int i=1; i<=n; i++) {
            if(nums[i] != i) {
                return i;
            }
        }

        return n+1;
    }
};