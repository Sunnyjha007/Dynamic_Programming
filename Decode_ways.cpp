//leetcode - 91
//mcm variation
int solve(string &s,int i,vector<int>& dp,unordered_map<string,int>& map,int n){
        if(i==n)return 1;
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        string temp = "";
        for(int k=i;k<n;k++){
            temp+=s[k];
            if(map.find(temp)!=map.end()){
                 ans+=solve(s,k+1,dp,map,n);
            }else{
                return dp[i] = ans;
            }
          
        }
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        unordered_map<string,int> map;
        for(int i=1;i<=26;i++){
            map[to_string(i)]++;
        }
        int n = s.size();
        vector<int> dp(101,-1);
        return solve(s,0,dp,map,n);
}
