#include <bits/stdc++.h> 
void Reverse(vector<int> &a,int start,int end)
{
    if(start>=end)//base condition
        return;
    swap(a[start],a[end]);
    Reverse(a,start+1,end-1);    
}
vector<int> nextPermutation(vector<int> &a, int n)
{
    int idx=-1;
    //find the breaking point , dip point
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]<a[i+1])
        {
            idx=i;
            break;
        }
    }
    if(idx==-1)
    {
        //whole array is in decreasing order
        //just reverse it to get next permutaton
        reverse(a.begin(),a.end());
        return a;
    }

    //at idx we have got dip point
    for(int i=n-1;i>idx;i--)
    {
        if(a[i]>a[idx])
        {
            //found the just greater than a[idx]
            swap(a[idx],a[i]);
            break;
        }
    }

    //now after idx index, sort in ascending order
    Reverse(a,idx+1,n-1);
    return a;



}