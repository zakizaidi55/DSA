class Solution {
public:
    int findDayOfYear(string&date, vector<int>&cummMonth) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3));

        int totalDays = cummMonth[month-1] + day;
        return totalDays;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int>cummMonth(13, 0);
        cummMonth[1] = 31;

        for(int i=2; i<=12; i++) {
            cummMonth[i] = cummMonth[i-1] + monthDays[i-1];
        }

        int arriveAliceDay = findDayOfYear(arriveAlice, cummMonth);
        int leaveAliceDay = findDayOfYear(leaveAlice, cummMonth);
        int arriveBobDay = findDayOfYear(arriveBob, cummMonth);
        int leaveBobDay = findDayOfYear(leaveBob, cummMonth);

        int ans = min(leaveBobDay, leaveAliceDay) - max(arriveAliceDay, arriveBobDay) + 1;

        return ans < 0 ? 0 : ans;
    }
};
