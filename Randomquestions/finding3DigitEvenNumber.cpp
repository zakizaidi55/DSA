class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
//------------------------------Approach1------------------------------------------------------------
        // for(int i=0; i<digits.size(); i++) {
        //     for(int j=0; j<digits.size(); j++) {
        //         for(int k=0; k<digits.size(); k++) {

        //             if(i == j || i == k || j == k)
        //                 continue;
                    

        //             int num = digits[i] * 100 + digits[j] * 10 + digits[k];
        //             //catch yha galti kari thi
        //             if(num >= 100 && (num&1) == 0)
        //                 st.insert(num);
        //         }
        //     }
        // }
        // vector<int>ans(st.begin(), st.end());

        // sort(ans.begin(), ans.end());
        // return ans;


//------------------------------------Approach2-------------------------------------------------------
        unordered_map<int, int>mp;
        vector<int>result;

        for(int i=0; i<digits.size(); i++) {
            mp[digits[i]]++;
        }

        for(int i=1; i<=9; i++) {
            if(mp[i] == 0){
                continue;
            }

            mp[i]--;
            
            for(int j=0; j<=9; j++) {
                if(mp[j] == 0){
                    continue;
                }

                mp[j]--;

                for(int k=0; k<=8; k+=2) {
                    if(mp[k] == 0){
                        continue;
                    }
                    
                    mp[k]--;

                    int num = i*100 + j*10 + k;
                    result.push_back(num);
                    mp[k]++;
                }
                mp[j]++;
            }
            mp[i]++;
        }

        return result;
    }
};



