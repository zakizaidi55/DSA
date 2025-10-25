class Solution {
public:
    int totalMoney(int n) {
        int mondayMoney = 1;
        int ans = 0;
        int money = 0;
        for(int i=0; i<n; i++) {
            if(i%7 == 0) {
                // iska matlab hum monday par aagye h
                ans += mondayMoney;
                mondayMoney++;
                money = mondayMoney;
            }

            else {
                ans += money;
                money++;
            }
        }

        return ans;
    }
};


