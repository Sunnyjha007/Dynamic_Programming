//Recursive 
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    if(n==0||w==0)return 0;
    if(weight[n-1]<=w){
        return max(profit[n-1]+unboundedKnapsack(n,w-weight[n-1],profit,weight),unboundedKnapsack(n-1,w,profit,weight));
    }else{
        return unboundedKnapsack(n-1,w,profit,weight);
    }
}

//Dp-top Down
int solve(int n, int w, vector<int> &profit, vector<int> &weight,vector<vector<int>>& dp){
    if(n==0||w==0)return 0;
    if(dp[n][w]!=-1)return dp[n][w];
    if(weight[n-1]<=w){
        return dp[n][w] =max(profit[n-1]+solve(n,w-weight[n-1],profit,weight,dp),solve(n-1,w,profit,weight,dp));
    }else{
        return dp[n][w]= solve(n-1,w,profit,weight,dp);
    }
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
   vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    return solve(n,w,profit,weight,dp);
}


//Dp- bottom up 
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(weight[i-1]<=j){
                dp[i][j] = max(profit[i-1]+dp[i][j-weight[i-1]],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
