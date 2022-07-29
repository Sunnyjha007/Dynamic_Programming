int minimumTotal(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<vector<int>> dp(m,vector<int>(m,0));
        dp[0][0] = grid[0][0];
        for(int i=1;i<m;i++){
            for(int j=0;j<grid[i].size();j++){
                if(j==0){
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                }else if(j==grid[i].size()-1){
                    dp[i][j] = grid[i][j] + dp[i-1][j-1];
                }else{
                    dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                }
            }
        }
        return *min_element(dp[m-1].begin(),dp[m-1].end());
        
    }
};
/*

*/
/*
 int solve(vector<vector<int>>& grid,int m,int row,int col,vector<vector<int>>& dp){
        if(row<0||row>=m||col<0||col>=grid[row].size())return 0;
        if(dp[row][col]!=-1)return dp[row][col];
        return dp[row][col] =  grid[row][col] + min(solve(grid,m,row+1,col,dp),solve(grid,m,row+1,col+1,dp));
    }
    int minimumTotal(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        return solve(grid,m,0,0,dp);
    }
    */
/*
 int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++)dp[i] = triangle[n-1][i];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                dp[j] = min(dp[j],dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
*/
