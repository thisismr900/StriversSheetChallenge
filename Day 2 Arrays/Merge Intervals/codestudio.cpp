#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        for(int i=0;i<n;i++)
        {
            if(ans.empty() || ans.back()[1]< intervals[i][0])
            {//new interval comes or non-overlapping interval comes, i will
            //store in ans
                ans.push_back(intervals[i]);
            }
            else{
                //overlapping interval 
                ans.back()[1]=max( ans.back()[1], intervals[i][1] );
            }
        }
        return ans;
}

