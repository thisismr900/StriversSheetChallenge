#include <bits/stdc++.h> 
void findUnique(int idx,int n,vector<int> arr,vector<vector<int>>&ans,vector<int>&ds)
{
    //rec calls
    ans.push_back(ds);     
    for(int i=idx;i<n;i++)
    {
        if(i>idx && arr[i]==arr[i-1])continue;    
        ds.push_back(arr[i]);
        findUnique(i+1,n,arr,ans,ds);
        ds.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<int>ds;
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    findUnique(0,n,arr,ans,ds);   
    return ans;
}