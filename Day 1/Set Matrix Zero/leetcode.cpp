class Solution {
public:
// void markRow(vector<vector<int>> &matrix,int row)
// {
// 	for(int j=0;j<matrix[row].size();j++)
// 	{
// 		if(matrix[row][j]!=0)
// 			matrix[row][j]=-1000;
// 	}
// }
// void markCol(vector<vector<int>> &matrix,int col)
// {
// 	for(int i=0;i<matrix.size();i++)
// 	{
// 		if(matrix[i][col]!=0)
// 			matrix[i][col]=-1000;
// 	}
// }
    void setZeroes(vector<vector<int>>& matrix) {
        //optimal
        int n=matrix.size();
        int m=matrix[0].size();
        bool rowZero=false,colZero=false;
        for(int j=0;j<m;j++){
            if(matrix[0][j]==0)
            {
                rowZero=true;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0)
            {
                colZero=true;
                break;
            }
        }

        //iterate the inner matrix and mark 1st row and 1st col element 0
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        //solve the inner matrix with the help of first row and 1st column
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if( matrix[i][0]==0 || matrix[0][j]==0)
                   matrix[i][j]=0;
            }
        }

        //now solve 1st row using rowZero variable
        if(rowZero==true)
        {
            for(int j=0;j<m;j++)
                matrix[0][j]=0;
        }
        //now solve 1st col using colZero variable
        if(colZero==true)
        {
            for(int i=0;i<n;i++)
                matrix[i][0]=0;
        }
    }

        // Write your code here.
    // int n=matrix.size();
    // int m=matrix[0].size();
    // vector<int> row(n,0);
    // vector<int> col(m,0);
	// for(int i=0;i<matrix.size();i++)
	// {
	// 	for(int j=0; j<matrix[i].size(); j++)
	// 	{
	// 		if(matrix[i][j]==0)
	// 		{
    //             row[i]=1;
    //             col[j]=1;
	// 		}
	// 	}
	// }

	// for(int i=0;i<matrix.size();i++)
	// {
	// 	for(int j=0; j<matrix[i].size(); j++)
	// 	{
	// 		if(row[i]==1 || col[j]==1)
	// 		{
	// 			matrix[i][j]=0;
	// 		} 
	// 	}
	// }
    // }
};