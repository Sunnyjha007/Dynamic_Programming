int solve(int arr[],int i,int j,vector<vector<int>>& dp){
    if(i>=j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans = INT_MAX;
    for(int k=i;k<j;k++){
        int temp = arr[k]*arr[j]*arr[i-1] + solve(arr,i,k,dp)+solve(arr,k+1,j,dp);
        ans = min(ans,temp);
    }
    return dp[i][j] = ans;
}
    int matrixMultiplication(int n, int arr[])
{
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(arr,1,n-1,dp);
}
