//dp solution
int solve(vector<int>& prices,int i,bool buy,vector<vector<int>>& dp){
        if(i>=prices.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
            return dp[i][buy] = max(solve(prices,i+1,buy,dp), -prices[i]+solve(prices,i+1,!buy,dp));
        }else{
            return dp[i][buy] = max(solve(prices,i+1,buy,dp),prices[i]+solve(prices,i+1,!buy,dp));
        }
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,1,dp);
}
// normal view 
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans=0;
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]){
                ans+=prices[i]-prices[i-1];
            }
        }return ans;
}
