//Leetcode - 2207
long long  solve(string text, string pattern){
        int m = text.size(),n = pattern.size();
        vector<vector<long long >> dp(m+1,vector<long long >(n+1,0));
        for(int i=0;i<=m;i++)dp[i][0] =1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text[i-1]==pattern[j-1]){
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
}
    long long maximumSubsequenceCount(string text, string pattern) {
        return max(solve(pattern[0]+text,pattern),solve(text+pattern[1],pattern));
}
