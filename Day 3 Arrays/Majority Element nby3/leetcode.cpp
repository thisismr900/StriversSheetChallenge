class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
	// better using hashing
	vector<int>ans;
	map<int,int> mpp;
	int n=nums.size();
	int mini=(n/3)+1;

	for(int i=0; i<n; i++)
	{
		mpp[nums[i]]++;
		if( mpp[nums[i]] == mini)
			ans.push_back(nums[i]);

		if(ans.size()==2)break;	
	}
	sort(ans.begin(),ans.end());
	return ans;
    }
};
