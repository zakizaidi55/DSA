class Solution {
public:
    void maxProfitFind(vector<int>& prices, int index, int& minPrice, int& maxProfit) {
        // base case
        if(index == prices.size()) 
            return;


        // solution for one case
        if(prices[index] < minPrice) 
            minPrice = prices[index];

        int todayProfit = prices[index] - minPrice;

        if(todayProfit > maxProfit)
            maxProfit = todayProfit;

        maxProfitFind(prices, index+1, minPrice, maxProfit);  
        
    }
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;

        maxProfitFind(prices, 0, minPrice, maxProfit);
        return maxProfit;
    }
};