#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int topleft = 0, topright = m-1, bottomright = n-1, bottomleft = 0;

    while (topleft < topright && bottomleft < bottomright){
        int temp = mat[topleft][bottomleft];
        for (int i = topleft + 1 ; i <= bottomright ; i++){
            mat[i-1][bottomleft] = mat[i][bottomleft];
        }
        for (int i = bottomleft + 1 ; i <= topright ; i++){
            mat[bottomright][i-1] = mat[bottomright][i];
        }

        for (int i = bottomright-1 ; i >= topleft ; i--){
            mat[i+1][topright] = mat[i][topright];
        }
        for (int i = topright-1 ; i >= bottomleft ; i--){
            mat[topleft][i+1] = mat[topleft][i];
        }
        mat[topleft][bottomleft+1] = temp;
        topleft++;
        bottomleft++;
        topright--;
        bottomright--;
    }

}


// #include <bits/stdc++.h>

// void rotateMatrix(vector<vector<int>> &mat, int n, int m)
// {
//   //take care of edge cases when n=1 
//     int prev;
//     n=1? (prev=mat[0][m-1]) :(prev=mat[1][0]); 
    
//     int curr=mat[0][0];

//     int left=0,right=m-1;
//     int top=0,bottom=n-1;

//     while(top<bottom && left<right)
//     {
//       //first row traversal
//       for(int col=left; col<=right; col++)
//       {
//         curr=mat[top][col];
//         mat[top][col]=prev;
//         prev=curr;
//       }
//       //first row traverse completed
//       top++;
      
//       //traverse last col
//       for(int row=top;row<=bottom;row++)
//       {
//         curr=mat[row][right];
//         mat[row][right]=prev;
//         prev=curr;
//       }
//       right--;//last col traversal complete

//       //traverse last row
//       for(int col=right;col>=left;col--)
//       {
//         curr=mat[bottom][col];
//         mat[bottom][col]=prev;
//         prev=curr;
//       }
//       bottom--;//last row traverse complete

//       //traverse first col
//       for(int row=bottom; row>=top ;row--)
//       {
//         curr=mat[row][left];
//         mat[row][left]=prev;
//         prev=curr;
//       }
//       left++;//first col traversal complete

//     }
//     mat[top-1][left]=prev;
// }