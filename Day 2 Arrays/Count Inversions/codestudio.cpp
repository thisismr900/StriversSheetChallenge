#include <bits/stdc++.h> 
// long long getInversions(long long *arr, int n){
    //BRUTE  
    //      TC:O(N^2)  
    //      SC: O(1)
//     long long countOfInversions=0;
//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=i+1;j<n;j++)
//             if(arr[i]>arr[j])
//                 countOfInversions++;
//     }
//     return countOfInversions;
// }

//OPTIMAL
long long cnt=0;

void merge(long long *arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) 
        {
            temp.push_back(arr[left]);
            left++;
        }
        else 
        {
            temp.push_back(arr[right]);
            cnt+=mid-left+1;
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) 
        arr[i] = temp[i - low];
    
}

void mergeSort(long long *arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}



long long getInversions(long long *arr, int n){
    mergeSort(arr,0,n-1);
    return cnt;
}