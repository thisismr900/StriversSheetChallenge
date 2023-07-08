#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    if(n==0)return 0;
    int longest=1;

    //step1 : Put everything into the unordered-set
    unordered_set<int>set;
    for(int i=0;i<n;i++)   //O(N)
        set.insert(arr[i]);    //unordered-set operations is O(1) assuming no collisions

    //step2
    for(auto it:set)
    {
        int cnt=1;
        if(set.find(it-1)==set.end())//u are the first element of the sequence, start counting
        {
            int x=it;
            while(set.find(x+1)!=set.end())
            {
                x++;
                cnt++;
            }
            longest=max(longest,cnt);
        }
    } 


    return longest;
}