//Leetcode - 647
int countSubstrings(string s) {
        int n = s.size(),ans=n;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)dp[i][i]=1;
        for(int i=1;i<n;i++){
            if(s[i-1]==s[i]){
                dp[i-1][i] = 1;
                ans++;
            }
        }
        for(int i=3;i<=n;i++){
            for(int j=0;j<n-i+1;j++){
                if(s[j]==s[j+i-1]&&dp[j+1][j+i-2]==1){
                    dp[j][j+i-1]=1;ans++;
                }
            }
        }
        return ans;
    }
};
//top - down tle O(n^3)
int solve(string s,int i,int j,vector<vector<int>>& dp){
        if(i>=j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]!=s[j])return dp[i][j]=0;
        return  dp[i][j] = solve(s,i+1,j-1,dp);
    }
    int countSubstrings(string s) {
        int n = s.size();
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j,dp))ans++;
            }
        }
        return ans;
    }
*/
