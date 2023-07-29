class Solution {
private:
bool isPalindrome(string s, int start, int end)
{
    if(start>=end)return true; //base case 1
    if(s[start]!=s[end] ) //base case 2
        return false;
    return isPalindrome(s,start+1,end-1);
    
}
void func( string s, int idx,vector<string>&ds,vector<vector<string>>&ans)
{
    //base case
    if(idx== s.size())
    {
        //insert into ans
        ans.push_back(ds);
    }

    for(int i=idx;i<s.size();i++)
    {
        //check if [idx to i] forms a palindrome
        if(isPalindrome(s,idx,i))
        {
            ds.push_back(s.substr(idx,i-idx+1));
            func(s,i+1,ds,ans);
            ds.pop_back();
        }
    }
}
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        func(s,0,ds,ans);
        return ans;
    }
};