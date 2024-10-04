class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = accumulate(skill.begin(), skill.end(), 0LL);
        if(skill.size() == 2) {
            return skill[0] * skill[1];
        } 

        // if(sum % 2 != 0){
        //     return -1;
        // }
        
        sort(skill.begin(), skill.end());

        int i = 0;
        int j = skill.size()-1;

        long long ans = 0;

        unordered_map<long long, int>mp;
        while(i < j) {
            long long sum = skill[i] + skill[j];
            long long product = skill[i] * skill[j];
            ans += product;
            mp[sum]++;

            if(mp.size() > 1) {
                return -1;
                break;
            }
            i++;
            j--;
        }

        return ans;
    }
};