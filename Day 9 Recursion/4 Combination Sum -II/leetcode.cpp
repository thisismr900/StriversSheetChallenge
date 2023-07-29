class Solution {
private:
    void func(vector<int>& candidates, int target,int ind, vector<int>&ds,vector<vector<int>>&ans)
    {
        //base case
        if(target==0)
        {        
            ans.push_back(ds);
            return;
        }

        //rec calls
        for(int i=ind;i<candidates.size();i++)
        {
            if(i>ind && candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break; //no need to continue unnecessary rec calls
            ds.push_back(candidates[i]);
            func(candidates,target-candidates[i],i+1,ds,ans);
            ds.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        func(candidates,target,0,ds,ans);
        return ans;
    }
};