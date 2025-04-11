class Solution {
public:
    bool isSymmetric(string&number) {
        int length = number.length();
        int leftPart = 0;
        int rightPart = 0;
        for(int i=0; i<length/2; i++) {
            leftPart += number[i] - '0';
        }

        for(int i=length/2; i<length; i++) {
            rightPart += number[i] - '0';
        }

        return leftPart == rightPart;
    }


    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i=low; i<=high; i++) {
            string number = to_string(i);
            if(number.length()%2 != 0)
                continue;
            if(isSymmetric(number)) 
                ans++;
        }

        return ans;
    }
};


