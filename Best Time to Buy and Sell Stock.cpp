int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minele = INT_MAX,maxprofit=0;
        for(int i=0;i<n;i++){
            minele = min(minele,prices[i]);
            maxprofit = max(maxprofit,prices[i]-minele);
        }
        return maxprofit;
}
//dp solution
int solve(vector<int>& prices,int i,int k,int buy,vector<vector<int>>& dp){
        if(i>=prices.size()||k<=0)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
            return dp[i][buy] = max(solve(prices,i+1,k,buy,dp),-prices[i]+solve(prices,i+1,k,!buy,dp));
        }else{
            return dp[i][buy] = max(solve(prices,i+1,k,buy,dp),prices[i]+solve(prices,i+1,k-1,!buy,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,1,1,dp);
}
//slight variation
// The logic to solve this problem is same as "max subarray problem" using Kadane's Algorithm. Since no body has mentioned this so far, I thought it's a good thing for everybody to know.

// All the straight forward solution should work, but if the interviewer twists the question slightly by giving the difference array of prices, Ex: for {1, 7, 4, 11}, if he gives {0, 6, -3, 7}, you might end up being confused.

// Here, the logic is to calculate the difference (maxCur += prices[i] - prices[i-1]) of the original array, and find a contiguous subarray giving maximum profit. If the difference falls below 0, reset it to zero.

public int maxProfit(int[] prices) {
        int maxCur = 0, maxSoFar = 0;
        for(int i = 1; i < prices.length; i++) {
            maxCur = Math.max(0, maxCur += prices[i] - prices[i-1]);
            maxSoFar = Math.max(maxCur, maxSoFar);
        }
        return maxSoFar;
}
