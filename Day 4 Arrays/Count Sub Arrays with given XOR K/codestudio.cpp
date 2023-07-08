#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int k) {

//optimal: 
    
    int count=0 , xorr=0;    
    int n=a.size();
    unordered_map<int,int>map;

    for(int currentIdx = 0; currentIdx < n ; currentIdx++)
    {
        xorr^=a[currentIdx];

        if(xorr==k)
            count++;

        int x=(xorr ^ k);
        
        //find if previously we had x, if yes also count of such x will be added to answer
        if(map.find(x)!=map.end())
        {
            count+=map[x];
        }
        
        map[xorr]++;
        
        
    }
    return count;






    //brute

    // int cnt=0;
    // int n=a.size();
    // for(int i=0;i<n;i++)
    // {
    //     int xorr=0;
    //     for(int j=i;j<n;j++)
    //     {
    //         xorr^=a[j];
    //         if(xorr==k)
    //             cnt++;
    //     }
    // }
    // return cnt;
}