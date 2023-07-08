class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        int cnt=1,maxCnt=1;
        sort(nums.begin(),nums.end());

        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1]+1)
            {
                cnt++;
                maxCnt=max(maxCnt,cnt);
            }
            else if(nums[i]==nums[i-1])
            {
                continue;
            }
            else
                cnt=1;
        }
        return maxCnt;
    }
};