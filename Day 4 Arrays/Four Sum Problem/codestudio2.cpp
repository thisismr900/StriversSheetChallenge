#include <bits/stdc++.h>

string fourSum(vector<int> a, int target, int n) {
    if(n<4)return "No";
    
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
    {
        if(i>0 && a[i]==a[i-1]) continue;

        for(int j=i+1; j<n;j++)
        {
            if(j>i+1 && a[j]==a[j-1])   continue;

            //2 pointers
            int left=j+1;
            int right=n-1;
            
            while(left<right)
            {
                long long sum=a[i];
                sum+=a[j];
                sum+=a[left];
                sum+=a[right];

                if(sum==target)
                    return "Yes";

                else if(sum<target)
                {
                    left++;
                    while(a[left]==a[left-1]  && left<right) left++;
                }
                else{
                    right--;
                    while(a[right]==a[right+1] && left<right) right--;
                }
            }
        }
    }

    return "No";
}
