int uniquePaths(int m,int n){
         int row = 0,col=0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0){
                    dp[i][j] = 1;
                }else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
/*
vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0){
                    dp[i][j]=1;
                }else
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
*/
/*
int solve(int m,int n,int row,int col,vector<vector<int>>& dp){
        if(row<0||row>=m||col<0||col>=n)return 0;
        if(row==m-1&&col==n-1)return 1;
        if(dp[row][col]!=-1)return dp[row][col];
        return dp[row][col] =  solve(m,n,row+1,col,dp) + solve(m,n,row,col+1,dp);
    }
    int uniquePaths(int m,int n){
         int row = 0,col=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,row,col,dp);
    }
*/
/*
  int solve(int m,int n,int row,int col){
        if(row<0||row>=m||col<0||col>=n)return 0;
        if(row==m-1&&col==n-1)return 1;
        return solve(m,n,row+1,col) + solve(m,n,row,col+1);
    }
    int uniquePaths(int m,int n){
         int row = 0,col=0;
        return solve(m,n,row,col);
    }
*/
/*
if(x<0||x>m-1||y<0||y>n-1)return 0;
        if(dp[x][y]!=-1)return dp[x][y];
        dp[x][y] = solve(m,n,dp,x+1,y) + solve(m,n,dp,x,y+1);
        return dp[x][y];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int x=0,y=0;
        dp[m-1][n-1]=1;
        return solve(m,n,dp,x,y);
        
*/
/*
int uniquePaths(int m,int n){
         vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0){
                    dp[i][j]=1;
                }else
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
*/
