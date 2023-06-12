class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //optimal
        int n=nums.size();
        int ele;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(cnt==0)
            {
                ele=nums[i];
                cnt=1;
            }
            else if(nums[i]==ele)
            {
                cnt++;
            }
            else 
                cnt--;
        } 
    return ele;
    }
};