class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    
        //transpose the original matrix
	    int n=matrix.size();

        for (int i = 0; i < n-1; i++) {
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
        
        //reverse each row of original matrix
        for(int row=0;row<n;row++)
        {
            reverse(matrix[row].begin(),matrix[row].end());
        }
        
    }
};


	
