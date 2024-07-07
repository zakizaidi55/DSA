class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int noOfBottlesToBeDrinkAgain = numBottles;
        int remainingEmptyBottles = 0;
        int noOfBottlesToBeDrink = 0;
        while(true) {
                       
            noOfBottlesToBeDrink = noOfBottlesToBeDrinkAgain / numExchange; // itni bottle dobara pee sakte h
            remainingEmptyBottles = noOfBottlesToBeDrinkAgain % numExchange; // itni khali rahegi 

            ans += noOfBottlesToBeDrink;
            cout << ans << endl;

            noOfBottlesToBeDrinkAgain = remainingEmptyBottles + noOfBottlesToBeDrink;
            cout << "noOfBottlesToBeDrinkAgain " << noOfBottlesToBeDrinkAgain << endl;

            if((noOfBottlesToBeDrink + remainingEmptyBottles ) < numExchange) 
                break;
        }

        return ans;
    }
};