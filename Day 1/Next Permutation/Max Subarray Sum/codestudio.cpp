#include <bits/stdc++.h> 
long long maxSubarraySum(int a[], int n)
{
    long long maxSum=LONG_MIN;
    
    //optimal
    long long sum=0;

    int idx=0;
    bool allNegative=true;
    while(idx<n)
    {
        if(a[idx]>0)
            allNegative=false;
        sum=sum+a[idx];
        if(sum>maxSum)
            maxSum=sum;

        if(sum<0) //if sum<0 make it zero //no benefit of carring negative sum
            sum=0;
        
        idx++;
    }
    if(allNegative)
    {
        //return max element
        // int maxElement=a[0];
        // for(int i=1;i<n;i++)
        //     maxElement=max(a[i],maxElement);
        // maxSum=maxElement;
        maxSum=0;

    }
    return maxSum;




//better
    // for(int i=0;i<n;i++)
    // {
    //     long long sum=0;
    //     {
    //         for(int j=0;j<n;j++)
    //         {
    //             sum+=a[j];
    //             if(sum>maxSum)
    //                 maxSum=sum;
    //         }
    //     }
    // }

}