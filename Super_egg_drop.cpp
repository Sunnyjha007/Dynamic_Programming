int helper(int e, int f, vector<vector<int>> &dp){
        if(f==0 || f==1) return f;
        if(e<=1) return f;
        if(dp[e][f] != -1) return dp[e][f];
        int ans = INT_MAX, i = 1, j = f, temp = 0;
        while(i<=j){
            int mid = (i+j)/2;
            int left = helper(e-1,mid-1,dp);
            int right = helper(e,f-mid,dp);
            int temp = 1 + max(left, right);
            if(left < right) i = mid+1;
            else j = mid-1;
            ans = min(temp, ans);
        }
        return dp[e][f] = ans;
    }
    int superEggDrop(int e, int f) {
        vector<vector<int>> dp(e+1, vector<int>(f+1,-1));
        return helper(e,f,dp);
}
