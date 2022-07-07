//Leetcode - 97
//top-down
bool solve(string s1, string s2, string s3,int n1,int n2,int m,vector<vector<int>>& dp){
        if(n1<0&&n2<0&&m<0)return true;
        if(n1>=0&&n2>=0&&dp[n1][n2]!=-1)return dp[n1][n2];
        if(n1>=0&&n2>=0&&m>=0&&s1[n1]==s3[m]&&s2[n2]==s3[m]){
            return dp[n1][n2] = solve(s1,s2,s3,n1-1,n2,m-1,dp)||solve(s1,s2,s3,n1,n2-1,m-1,dp);
        }else if(n1>=0&&m>=0&&s1[n1]==s3[m]){
            return solve(s1,s2,s3,n1-1,n2,m-1,dp);
        }else if(n2>=0&&m>=0&&s2[n2]==s3[m]){
            return solve(s1,s2,s3,n1,n2-1,m-1,dp);
        }
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(),n2 = s2.size(),m = s3.size();
        if((n1+n2)!=m)return false;
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return solve(s1,s2,s3,n1-1,n2-1,m-1,dp);
}
//Bottom-Up
