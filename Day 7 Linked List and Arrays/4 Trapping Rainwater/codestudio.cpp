#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    if(n<=1)return 0;
    long left[n]={};
    long right[n]={};
    left[0]=arr[0];
    right[n-1]=arr[n-1];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>left[i-1])
            left[i]=arr[i];
        else 
            left[i]=left[i-1];
    }
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>right[i+1])
            right[i]=arr[i];
        else
            right[i]=right[i+1];
    }
    long trappedWater=0;
    for(int i=0;i<n;i++)
    {
        trappedWater+=min(left[i],right[i]) - arr[i];
    }
    
    return trappedWater;
}