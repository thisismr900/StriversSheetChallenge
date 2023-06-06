#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int M=-1,R=-1;
	vector<int>freq(n+1,0);
	for(int i=0;i<n;i++)
		freq[arr[i]]+=1;
	
	for(int i=1;i<n+1;i++)
	{
		if(freq[i]==0)
			M=i;
		else if(freq[i]>1)
			R=i;
		
		if(M!=-1 && R!=-1)
			break;
	}
	
	pair<int,int>ans;
	ans.first=M;
	ans.second=R;
	return ans;
	
}
