class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(grid[i][0]!=1)dp[i][0] = 1;
            else break;
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]!=1)dp[0][j] = 1;
            else break;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                    if(grid[i][j]!=1){
                        dp[i][j] = dp[i-1][j]+dp[i][j-1];
                    }
            }
        }
        return dp[m-1][n-1];
        
    }
   
};
/*
int solve(vector<vector<int>>& grid,int m,int n,int row,int col,vector<vector<int>>& dp){
        if(row<0||row>=m||col<0||col>=n||grid[row][col]==1)return 0;
        if(row==m-1&&col==n-1)return 1;
        if(dp[row][col]!=-1)return dp[row][col];
        return dp[row][col] =  solve(grid,m,n,row+1,col,dp) + solve(grid,m,n,row,col+1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(grid,m,n,0,0,dp);
    }
*/
