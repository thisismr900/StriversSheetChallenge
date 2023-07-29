#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int s) {
	vector<vector<int>>ans;

	sort(arr.begin(),arr.end());
	for(int i=0;i<=n-3;i++)
	{
		if(i>0 && arr[i]==arr[i-1])continue;
		int j=i+1;
		int k=n-1;
		while(j<k)
		{
		int sum=arr[i]+arr[j]+arr[k];
		if( sum > s )
			k--;
		else if(sum < s )
			j++;
		else
		{	//we have got the triplet
			vector<int>triplet={arr[i],arr[j],arr[k]};//in sorted order
			ans.push_back(triplet);
			do{ j++;  }while(j<k && arr[j]==arr[j-1]);
			do{ k--;  }while(j<k && arr[k]==arr[k+1]);
		}
		}

	}
	return ans;
}

/*
	BETTER
set<vector<int>>ansSet;
	for(int i=0;i<n;i++)
	{
		set<int>hashSet;
		for(int j=i+1;j<n;j++)
		{
			int third= s-( arr[i] + arr[j] );
			if(hashSet.find(third)!=hashSet.end())
			{
				//k in hashSet
				//triplet found
				vector<int>temp={arr[i],arr[j],third};
				sort(temp.begin(),temp.end());//sort the triplet to prevent duplicacy
				ansSet.insert(temp);//insert the sorted triplet into answerSet
			}
			//before j++ insert arr[j] in hashSet
			hashSet.insert(arr[j]);
		}
	}
	vector<vector<int>>ans(ansSet.begin(),ansSet.end());*/