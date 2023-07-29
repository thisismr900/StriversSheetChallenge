void findSubsetSum( int idx, int sum,vector<int> &num, vector<int> &sumSubset)
{
	//base case
	if(idx==num.size())
	{
		sumSubset.push_back(sum);
		return;
	}
	//recursive calls
	findSubsetSum(idx+1, sum+num[idx],num,sumSubset);
	findSubsetSum(idx+1, sum,num,sumSubset);
		
}
vector<int> subsetSum(vector<int> &num){
	
	vector<int>sumSubset;
	findSubsetSum(0,0,num,sumSubset);
	sort(sumSubset.begin(),sumSubset.end());
	return sumSubset;	
}