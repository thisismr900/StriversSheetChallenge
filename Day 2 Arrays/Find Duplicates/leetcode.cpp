class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    //OPTIMAL: 2 POINTER APPROACH: SLOW AND FAST POINTER TC:O(N) SC:O(1)
	int slow=nums[0],fast=nums[0];
	do{
		slow=nums[slow];
		fast=nums[nums[fast]];
	}while(slow!=fast);

	fast=nums[0];
	while(slow!=fast)
	{
		fast=nums[fast];
		slow=nums[slow];
	}
	return slow;

    }
};
