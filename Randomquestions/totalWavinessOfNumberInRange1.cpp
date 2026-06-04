class Solution {
public:
    int findScore(int num) {
        string s = to_string(num);
        if(s.length() < 3)
            return 0;

        int score = 0;
        for(int i=1; i<=s.length()-2; i++) {
            if(s[i] > s[i-1] && s[i] > s[i+1])
                score++;
            if(s[i] < s[i-1] && s[i] < s[i+1])
                score++;
        }

        return score;
    }
    int totalWaviness(int num1, int num2) {
        int score = 0;
        for(int num=num1; num<=num2; num++) {
            score += findScore(num);
        }
        return score;
    }

};


