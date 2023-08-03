class Solution {
private:
    bool isSafe(int row, int col, vector<string>&board)
    {
        //check for row attack
        for(int j=0;j<board.size();j++)
        {
            if(j==col)continue;
            if(board[row][j]=='Q')
                return false;
        }
        
        //check diagonal attack
        int i=row,j=col;
        while(i>=0 && j>=0)
        {
            if(board[i][j]=='Q')return false;
            i--;j--;
        }
        i=row;
        j=col;
        while(i<board.size() && j>=0)
        {
            if(board[i][j]=='Q')return false;
            i++;j--;
        }
        return true;
    }
    void solve(int col,vector<vector<string>>&ans,vector<string>&board)
    {
        if(col==board.size())//base case
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<board.size();row++)
        {
            if(isSafe(row,col,board))
            {
                board[row][col]='Q';
                solve(col+1,ans,board);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board;
        string s(n,'.');
        for(int i=0;i<n;i++)
            board.push_back(s);
        solve(0,ans,board);
        return ans;
    }
    
};