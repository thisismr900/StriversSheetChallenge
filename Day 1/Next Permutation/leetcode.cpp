class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //first find the dipping point
        int idx=-1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                idx=i;
                break;
            }
        }
        if(idx==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }

        // find the just next greater no that nums[idx]
        for(int i=nums.size()-1;i>idx;i--)
        {
            if(nums[i]>nums[idx])
            {
                swap(nums[i],nums[idx]);
                break;
            }
        } 
        //now after idx, sort in increasing order
        reverse(nums.begin()+idx+1,nums.end());
    }
};