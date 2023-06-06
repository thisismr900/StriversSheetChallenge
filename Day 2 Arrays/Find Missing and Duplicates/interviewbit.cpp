#include<bits/stdc++.h>
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    vector<int>freq(n+1,0);
    int duplicate=-1,missing=-1;
    
    for(int i=0;i<A.size();i++)
    {
            freq[A[i]]++;    
    }

    for(int i=1;i<freq.size();i++)
    {
        if(freq[i]==0)
            missing=i;
        if(freq[i]>1)
            duplicate=i;
        
        if(missing!=-1 && duplicate !=-1)
            break;
        
    }
    vector<int>ans;
    ans[0]=duplicate; 
    ans[1]=missing;
    return ans;
    
}
