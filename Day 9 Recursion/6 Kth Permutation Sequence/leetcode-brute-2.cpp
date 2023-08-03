class Solution {
private:
void permutationHelper(int index,vector<string> &ans, int n, string& s)
{
    //base case
    if(index==n)
    {
        ans.push_back(s);
        return;
    }
    //rec calls
    for(int i=index;i<n;i++)
    {
        swap(s[i],s[index]);
        permutationHelper(index+1,ans,n,s);
        swap(s[i],s[index]);
    }
}
public:
    string getPermutation(int n, int k) {
        string s;//empty string
        for(int i=1;i<=n;i++)
            s.push_back(i+'0');
        vector<string> ans;
        permutationHelper(0,ans,n,s);
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};