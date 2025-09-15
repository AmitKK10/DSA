class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit =0;
        int minProfit = INT_MAX;

        for(int price :prices)
        {
            minProfit = min(price,minProfit);
            maxProfit = max(maxProfit,(price-minProfit));
        }

        return maxProfit;
    }
};