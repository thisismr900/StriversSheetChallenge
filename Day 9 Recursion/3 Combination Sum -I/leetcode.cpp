class Solution {
private:
    void func(vector<int>& candidates, int target, int idx, int n,vector<vector<int>>&ans, vector<int>&ds)
    {
        //base case
        if(idx==n)
        {
            if(target==0)
                ans.push_back(ds);
            return;            
        }
        //recursive calls
        //check if pick possible
        if(target >= candidates[idx])
        {
            ds.push_back(candidates[idx]);
            func(candidates,target-candidates[idx],idx,n,ans,ds);
            ds.pop_back();
        }
        //not pick - rec call
        func(candidates,target,idx+1,n,ans,ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n=candidates.size();
        func(candidates,target,0,n,ans,ds);
        return ans;
    }
};