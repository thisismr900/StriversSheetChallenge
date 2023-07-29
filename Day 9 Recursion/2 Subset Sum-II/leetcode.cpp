class Solution {
private:
    void func(vector<int>& nums,int n,int ind, vector<int>& ds,vector<vector<int>>&ans)
    {
 //base case na likho tab bhi chalega because hum already loop mein fixed no of calls ka rahe hai so ek time bas ruk jayega calls for a level
        
        ans.push_back(ds);
        //recursive calls
        for(int i=ind;i<n;i++)
        {
            if(i==ind)
            {   //first time insert into ds
                ds.push_back(nums[i]);
                func(nums,n,i+1,ds,ans);
                ds.pop_back();
            }
            else{
                if(nums[i]!=nums[i-1])
                {
                    ds.push_back(nums[i]);
                    func(nums,n,i+1,ds,ans);
                    ds.pop_back();
                }
            }
        }

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ds;
        vector<vector<int>>ans;
        func(nums,n,0,ds,ans);
        return ans;
    }
};