 int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = grid[0][0];
        for(int i=1;i<m;i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for(int i=1;i<n;i++){
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                    dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
                }
        }
        return dp[m-1][n-1];
    }
};
/*
 int solve(vector<vector<int>>& grid,int m,int n,int row,int col,vector<vector<int>>& dp){
        if(row<0||row>=m||col<0||col>=n)return INT_MAX;
        if(row==m-1&&col==n-1)return grid[row][col];
        if(dp[row][col]!=-1)return dp[row][col];
        return dp[row][col] = grid[row][col] + min(solve(grid,m,n,row+1,col,dp),solve(grid,m,n,row,col+1,dp)); 
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(grid,m,n,0,0,dp);
        
    }
*/
