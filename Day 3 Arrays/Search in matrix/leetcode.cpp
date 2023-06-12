class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        //first column mein hi binary search laga ke pata karlo konse row mein search karni padegi
        int top=0,bottom=n;
        int mid;
        while(top<=bottom)
        {
            mid=(top+bottom)/2;
            if(matrix[mid][0]<target && matrix[mid][m]<target)            
                top=mid+1;

            else if(matrix[mid][0]>target)
                bottom=mid-1;
            
            else if(matrix[mid][0]==target || matrix[mid][m]==target ) 
                return true;
            
            else if(matrix[mid][0]<target && matrix[mid][m]< target )
            {//found the row jisme target element present ho sakta hai
                int left=0,right=m,middle;
                while(left<=right)
                {
                    middle=(left+right)/2;
                    if(matrix[mid][middle]==target)return true;
                    else if(matrix[mid][middle]<target)
                        right=middle-1;
                    else
                        left=middle+1;
                }

            }
        }

        return false;
        




//brute force n2
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(matrix[i][j]==target)
        //             return true;                
        //     }
        // }
        // return false;
    }
};