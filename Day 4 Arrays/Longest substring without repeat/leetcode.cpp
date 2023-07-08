class Solution {
public:
    int lengthOfLongestSubstring(string input) {
    
        int n=input.size();
        if(n==0)return 0;
        int left=0,right=0;
        unordered_set<int>set;
        int longest=0;

        while(right<n)
        {
            if(set.find(input[right]) != set.end() ) //duplicate found
            {
                while(left<right && input[left]!=input[right])
                {
                    set.erase( input[left++]);
                }
                //now left is at duplicate , erase it from set and increase by 1
                set.erase( input[left++]);
            }
            longest=max(longest,right-left+1);
            set.insert(input[right++]); //push element in set
        }

        return longest;
    }
    
};