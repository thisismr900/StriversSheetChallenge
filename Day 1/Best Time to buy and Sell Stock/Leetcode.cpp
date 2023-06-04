class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int idx=1;
        int leastPrice=prices[0];
        int profit=0;
        int maximumProfit=0;

        while(idx<prices.size())
        {
            if(prices[idx]<leastPrice)
                leastPrice=prices[idx];
            //current profit
            profit=prices[idx]-leastPrice;
            if(profit>maximumProfit)
                maximumProfit=profit;
            idx++;
        }
        if(maximumProfit<0)
            maximumProfit=0;
        return maximumProfit;
    }
};