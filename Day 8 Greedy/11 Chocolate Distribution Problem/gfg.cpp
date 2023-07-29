#include <bits/stdc++.h> 
bool static cmp(pair<int,int>a,pair<int,int>b)
{
    double vpw1=(double)(a.second)/(double)(a.first);
    double vpw2=(double)(b.second)/(double)(b.first);
    return vpw1>vpw2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // ITEMS contains {weight, value} pairs.
    
    //sort items based on descending valuePerWeight
    sort(items.begin(),items.end(),cmp);
    
    double ansValue=0.00;
    int currWeight=0;
    for(auto item:items)
    {
        int newWeight=item.first;
        int newVal=item.second;
        if(currWeight + newWeight <= w)
        {
            //completely insert in knapsack
            currWeight+=newWeight;
            ansValue+=newVal;
        }
        else{
            //partially fill jitna ho paye ,then break
            int remainingWeight=w-currWeight;
            ansValue+= ( (double)newVal ) /( (double)(newWeight) ) * ((double)(remainingWeight));
            break;
        }
        if(currWeight==w)break;
    }
    return ansValue;    
}