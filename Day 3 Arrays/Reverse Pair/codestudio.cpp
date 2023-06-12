#include <bits/stdc++.h>

//int cnt=0;//global variable    (BAD PRACTICE)

void merge(vector<int> &arr, int low, int mid, int high)
{
	//we have to merge two sorted halves
	vector<int>temp;//temporary array
	int left=low;       //range of left:  [low,mid]
	int right=mid+1;   //range of right:  [mid+1,high]
    //storing elements in the temporary array in a sorted manner//
        while (left <= mid && right <= high) 
		{
          // smallest element is considered
          if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
          else if (arr[left] > arr[right])
            temp.push_back(arr[right++]);
        }
        // if elements on the left half are still left //
        while (left <= mid) 
            temp.push_back(arr[left++]);
     	//  if elements on the right half are still left //
        while (right <= high)
            temp.push_back(arr[right++]);
    
	// transfering all elements from temporary to arr //
    for (int i = low; i <=high;i++) 
          arr[i] = temp[i-low];
}




int countPairs(vector<int> &arr, int low, int mid, int high)
{
	int right=mid+1;   //range of right:  [mid+1,high]
	int count=0;
	for(int i=low; i<=mid;i++)
	{
		while(   right<=high && arr[i]>( 2*arr[right] )  )
		{
			right++;
		}
		count+= (right- (mid+1) );
	}
	return count;
}


int mergeSort(vector<int> &arr, int low, int high)
{
	int count=0;

	if(low>=high)return count;//base case
	int mid=(low+high)/2; //calculations

	//recursive calls
	count+=mergeSort(arr,low,mid);      // left half will me sorted
	count+=mergeSort(arr,mid+1,high);  // right half will me sorted

	//before merging the halves, no of pairs is counted
	count+=countPairs(arr,low,mid,high); 
	merge(arr,low,mid,high);	
	return count;
} 



int reversePairs(vector<int> &arr, int n){	
	return mergeSort(arr,0,n-1);
	// return cnt;
}




