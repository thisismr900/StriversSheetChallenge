#include <bits/stdc++.h>
void markRow(vector<vector<int>> &matrix,int row)
{
	for(int j=0;j<matrix[row].size();j++)
	{
		if(matrix[row][j]!=0)
			matrix[row][j]=-1;
	}
}
void markCol(vector<vector<int>> &matrix,int col)
{
	for(int i=0;i<matrix.size();i++)
	{
		if(matrix[i][col]!=0)
			matrix[i][col]=-1;
	}
}
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	for(int i=0;i<matrix.size();i++)
	{
		for(int j=0; j<matrix[i].size(); j++)
		{
			if(matrix[i][j]==0)
			{
				markRow(matrix,i);
				markCol(matrix,j);
			}
		}
	}

	for(int i=0;i<matrix.size();i++)
	{
		for(int j=0; j<matrix[i].size(); j++)
		{
			if(matrix[i][j]==-1)
			{
				matrix[i][j]=0;
			}
		}
	}
	
}