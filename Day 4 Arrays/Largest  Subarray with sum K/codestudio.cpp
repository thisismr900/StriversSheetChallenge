#include <bits/stdc++.h>

//here k=0
int LongestSubsetWithZeroSum(vector < int > arr) {

  int n=arr.size();
  if(n==0)return 0;
  // int k=0;
  int maxLength=0;
  int prefSum=0;
  unordered_map<int,int>map;
  for(int currentIdx=0; currentIdx<n; currentIdx++)
  {
    prefSum+=arr[currentIdx];
    if (prefSum == 0) {
      maxLength = currentIdx + 1;
      
    }
    //check in map if earlier a sum of (prefSum-k) was present or not
    if(map.find(prefSum)!=map.end())
    {
      int startIdx=map[prefSum]+1;
      maxLength=max( maxLength, currentIdx - startIdx +1 );
    }
    else{
      // if(map.find(prefSum)==map.end())
        map.insert({prefSum,currentIdx});
    }

  }
  return maxLength;
}