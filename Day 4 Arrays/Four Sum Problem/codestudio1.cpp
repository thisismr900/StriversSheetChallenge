#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.

     unordered_map<long long ,pair<int,int>> mp;

    for(int i = 0; i < n; i++){
       for(int j = i+1; j < n; j++){
           long long sum = arr[i]+arr[j] , find = target-sum;
           if(mp.find(find) != mp.end()){
               if(mp[find].first != i && mp[find].second != j){
                   return "Yes";
               }
           }
           mp[sum] = {i,j};
       } 
    }

    return "No";
}
