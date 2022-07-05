//GFG
//TLE - 35/40
//dp+recursion
set<string> solve(string s,string t,int m,int n,vector<vector<int>>& dp){
	    set<string> se;
	    if(m==0||n==0){
	        se.insert("");
	        return se;
	    }
	    if(s[m-1]==t[n-1]){
	        set<string> tmp = solve(s,t,m-1,n-1,dp);
	        for(auto i:tmp){
	            se.insert(i+s[m-1]);
	        }
	    }else{
	        if(dp[m-1][n]>=dp[m][n-1]){
	            se = solve(s,t,m-1,n,dp);
	        }
	        if(dp[m][n-1]>=dp[m-1][n]){
	            set<string> tmp = solve(s,t,m,n-1,dp);
	           se.insert(tmp.begin(),tmp.end());
	        }
	    }
	    return se;
	    
	}
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    int m = s.size(),n = t.size();
		    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
		    for(int i=1;i<=m;i++){
		        for(int j=1;j<=n;j++){
		            if(s[i-1]==t[j-1]){
		                dp[i][j] = 1 + dp[i-1][j-1]; 
		            }else{
		                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
		    vector<string> ans;
		    set<string> v = solve(s,t,m,n,dp);
		    for(auto i:v){
		        ans.push_back(i);
		    }
		    return ans;
		}
  //submited
  //backtracking
  set<string> st;
	void solve(string s,string t,int r,int c,string& temp,vector<string>& ans,int len ){
	    if(len==0){
	        if(st.find(temp)==st.end()){
	            st.insert(temp);ans.push_back(temp);
	        }
	        return;
	    }
	    if(r>=s.size()||c>=t.size())return;
	    for(int i=r;i<s.size();i++){
	        for(int j = c;j<t.size();j++){
	            if(s[i]==t[j]){
	                temp.push_back(s[i]);
	                solve(s,t,i+1,j+1,temp,ans,len-1);
	                temp.pop_back();
	            }
	        }
	    }
	}
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    // Code here
		    int m = s.size(),n = t.size();
		    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
		    for(int i=1;i<=m;i++){
		        for(int j=1;j<=n;j++){
		            if(s[i-1]==t[j-1]){
		                dp[i][j] = 1 + dp[i-1][j-1]; 
		            }else{
		                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
		    int len = dp[m][n];
		   vector<string> ans;
		   string temp = "";
		   solve(s,t,0,0,temp,ans,len);
		   sort(ans.begin(),ans.end());
		   return ans;
		}
    
    
