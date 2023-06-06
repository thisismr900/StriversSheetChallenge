#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){

	//B R U T E :TC:O(NlogN) SC:O(1)

	// sort(arr.begin(),arr.end());
	// for(int i=0;i<n-1;i++)
	// {
	// 	if(arr[i]==arr[i+1])
	// 		return arr[i];
	// }

	//B E T T E R uses hashing , frequency array: TC:O(N) SC:O(N)
	// int maxi=INT_MIN;
	// for(int i=0;i<n;i++)
	// 	if(arr[i]>maxi)
	// 		maxi=arr[i];

	// vector<int>freq(maxi+1,0);
	// for(int i=0;i<n;i++)
	// {
	// 	if(freq[arr[i]]==0)
	// 		freq[arr[i]]=1;
	// 	else if(freq[arr[i]]==1)
	// 		return arr[i];
	// }

	//OPTIMAL: 2 POINTER APPROACH: SLOW AND FAST POINTER TC:O(N) SC:O(1)
	int slow=arr[0],fast=arr[0];
	do{
		slow=arr[slow];
		fast=arr[arr[fast]];
	}while(slow!=fast);

	fast=arr[0];
	while(slow!=fast)
	{
		fast=arr[fast];
		slow=arr[slow];
	}
	return slow;

}
