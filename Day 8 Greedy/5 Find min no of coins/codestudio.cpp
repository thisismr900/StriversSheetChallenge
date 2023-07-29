#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    int countOfCoins=0;
    int coins[9]={1,2,5,10,20,50,100,500,1000};
    for(int i=8;i>=0;i--)
    {
        while(coins[i]<=amount)
        {
            amount-=coins[i];
            countOfCoins++;
        }
    }
    return countOfCoins;
}
