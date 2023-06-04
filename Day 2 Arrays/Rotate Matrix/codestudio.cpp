#include<vector>
 
void rotateMatrix(vector<vector<int>> &mat){
	//transpose the original matrix
	int  n=mat.size();
	int m=mat[0].size();
  for (int i = 0; i < n-1; i++) {
    for (int j = i + 1; j < m; j++)
      swap(mat[i][j], mat[j][i]);
  }

  //reverse each row of original matrix
  for(int row=0;row<n;row++)
  {
      reverse(mat[row].begin(),mat[row].end());
  }
	
}
