//brute
#include<bits/stdc++.h>
class Solution {
private:
void func(vector<int>& candidates, int target,int idx,set<vector<int>>&ansSet, vector<int>&ds)
{
    //base case
    if(idx==candidates.size())
    {
        if(target==0)
        {
            ansSet.insert(ds);
        }
        return;
    }

    //is picking possible?
    if(candidates[idx]<=target)
    {
        ds.push_back(candidates[idx]);
        func(candidates,target-candidates[idx],idx+1,ansSet,ds);
        ds.pop_back();
    }
    //not pick
    func(candidates,target,idx+1,ansSet,ds);
}    

    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        set<vector<int>>ansSet;
        sort(candidates.begin(),candidates.end());
        vector<int>ds;
        func(candidates,target,0,ansSet,ds);
        for(auto subset:ansSet)
        {
            sort(subset.begin(),subset.end());
            ans.push_back(subset);
        }
        return ans;
    }
};