#include<bits/stdc++.h>
vector<int> majorityElement(vector<int> v) {
	//O P T I M AL 
	int ele1;
	int ele2;
	int cnt1=0,cnt2=0;
	vector<int>ans;
	int n=v.size();

	for(int i=0;i<n ;i++)
	{
		if(cnt1==0 && ele2!=v[i])
		{
			cnt1=1;
			ele1=v[i];
		}
		else if(cnt2==0 && ele1!=v[i])
		{
			cnt2=1;
			ele2=v[i];
		}
		else if(ele1 ==v[i])	cnt1++;
		else if(ele2 == v[i])	cnt2++;
		else{
			cnt1--;
			cnt2--;
		}
	}
	int mini=(n/3)+1;
	cnt1=0;
	cnt2=0;
	//manual verifying
	for(int i=0;i<n;i++)
	{
		if(ele1==v[i])cnt1++;
		else if(ele2==v[i])cnt2++;
	}
	if(cnt1 >= mini)	ans.push_back(ele1);
	if(cnt2 >= mini)	ans.push_back(ele2);
	sort(ans.begin(),ans.end());

	return ans;
	
	
	
	





	// better using hashing
	vector<int>ans;
	map<int,int> mpp;
	int n=v.size();
	int mini=(n/3)+1;

	for(int i=0; i<n; i++)
	{
		mpp[v[i]]++;
		if( mpp[v[i]] == mini)
			ans.push_back(v[i]);

		if(ans.size()==2)break;	
	}
	sort(ans.begin(),ans.end());
	return ans;
}