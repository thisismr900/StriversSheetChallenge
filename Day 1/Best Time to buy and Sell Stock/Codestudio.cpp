#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int maxProfit=INT_MIN;


    for(int i=0;i<prices.size()-1;i++)
    {
        int profit=0;
        for(int j=i+1;j<prices.size();j++)
        {
            profit=prices[j]-prices[i];
            maxProfit=max(maxProfit,profit);
        }
    }
    if(maxProfit<0)maxProfit=0;
    return maxProfit;
}