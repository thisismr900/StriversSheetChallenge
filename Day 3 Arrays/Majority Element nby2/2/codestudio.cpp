#include <bits/stdc++.h> 
//better
int findMajorityElement(int arr[], int n) {
    if(n==0)return -1;
    unordered_map<int,int>map;
    int min=n/2;//floor

    for(int i=0;i<n;i++)//traverse array & create map
        map[arr[i]]++;
    unordered_map<int,int>:: iterator it=map.begin();
    while(it!=map.end())
    {
        if((it->second)>min) return it->first;
        it++;
    }
    return -1;
}