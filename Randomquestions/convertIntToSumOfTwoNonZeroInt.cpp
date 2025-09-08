class Solution {
public:
    // bool check(int num) {
    //     while(num) {
    //         // check agr humko koi digit 0 milti h
    //         if(num % 10 == 0) 
    //             return false;
            
    //         num = num/10;
    //     }
    //     return true;
    // }
    vector<int> getNoZeroIntegers(int n) {
        int a = n;
        int b = 0;
        int place = 1;


        while(n > 1) {
            int take = 1;
            if(n%10 == 1) 
                take = 2;
            
            a = a-take*place;
            b = take*place+b;

            n = (n-take)/10;
            place = place*10;
        }

        return {a,b};

        // for(int a=1; a<=n-1; a++) {
        //     int b = n-a;

        //     if(check(a) && check(b)) 
        //         return {a,b};
        // }

        // return {};
    }
};


