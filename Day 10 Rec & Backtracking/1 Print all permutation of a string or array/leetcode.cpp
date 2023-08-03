class Solution {
private:
    void permutationHelper(int index,vector<int>&nums,vector<vector<int>>&ans)
    {
        //base case
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        //rec calls
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            permutationHelper(index+1,nums,ans);
            swap(nums[i],nums[index]);
        }

    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permutationHelper(0,nums,ans);
        return ans;
    }
};