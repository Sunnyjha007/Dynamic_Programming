//recursion
 int solve(vector<int>& nums,int n){
        if(n==0)return nums[n];
        if(n<0)return 0;
        int pick = solve(nums,n-2) + nums[n];
        int non_pick = solve(nums,n-1);
        return max(pick,non_pick);
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,n-1);
}
//memo
int solve(vector<int>& nums,int n,vector<int>& dp){
        if(n==0)return nums[n];
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        int pick = solve(nums,n-2,dp) + nums[n];
        int non_pick = solve(nums,n-1,dp);
        return dp[n] =  max(pick,non_pick);
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(nums,n-1,dp);
}
//bottom up
int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int> dp(n+1,0);
        dp[0] = nums[0],dp[1] = max(nums[0],nums[1]);
        if(n==1)return dp[1];
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
}
//space optimization
int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        int prev1 = nums[0],prev2 = max(nums[0],nums[1]);
        int ans = prev2;
        for(int i=2;i<n;i++){
            ans = max(prev2,prev1+nums[i]);
            prev1 = prev2;
            prev2 = ans;
        }
        return ans;
}
