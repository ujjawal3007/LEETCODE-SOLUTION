class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mprofit = 0;
        int n = prices.size();
        int bestBuy = prices[0];
        for(int i = 1; i < n; i++) {
            if(bestBuy < prices[i]) {
                mprofit = max(mprofit, prices[i] - bestBuy);
            }
            else{
                bestBuy = min(bestBuy, prices[i]);
            }
        }
        return mprofit;
    }
};