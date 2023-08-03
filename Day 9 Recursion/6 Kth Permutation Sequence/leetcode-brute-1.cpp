#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class Solution {
private:
    void generateAllPermutations(int n, string& ds, vector<string>& ans,vector<int>& usedNo)
    {
        //base case
        if(usedNo.size()==n)
        {
            ans.push_back(ds);
            return;
        }

        //recursive calls
        for(int i=1;i<=n;i++)
        {
            if(find(usedNo.begin(), usedNo.end(), i) != usedNo.end())
                continue;
            ds.append(to_string(i));
            usedNo.push_back(i);
            generateAllPermutations(n,ds,ans,usedNo);
            usedNo.pop_back();
            ds.pop_back();
        }


    }
public:
    string getPermutation(int n, int k) {
        vector<string>ans;
        string ds;
        vector<int>usedNo;
        generateAllPermutations(n,ds,ans,usedNo);//generate all permutations recursively
        //sort the permutations
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};


