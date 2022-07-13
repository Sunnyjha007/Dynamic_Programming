//leetcode-241
//mcm variation
unordered_map<string,vector<int>> dp;
    vector<int> solve(string &s,int i,int j){
        if(i>j)return {};
        string key = to_string(i)+"_"+to_string(j);
        if(dp.find(key)!=dp.end())return dp[key];
        if(j-i<=1){
            string num = s.substr(i,j+1);
            return  dp[key] =  {stoi(num)};
        }
        vector<int> ans;
        for(int k=i;k<=j-1;k++){
            if(s[k]=='+'||s[k]=='-'||s[k]=='*'){
                vector<int> v1 = solve(s,i,k-1);
                vector<int> v2 = solve(s,k+1,j);
                char c = s[k];
                for(auto f:v1){
                    for(auto s:v2){
                        switch(c){
                                case '+':
                                ans.push_back(f + s);
                                break;
                            case '-':
                                ans.push_back(f - s);
                                break;
                            case '*':
                                ans.push_back(f * s);
                                break;
                            case '/':
                                ans.push_back(f / s);
                                break;
                        }
                    }
                }
            }
        }
        return dp[key] =  ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        dp.clear();
        vector<int> ans = solve(expression,0,n-1);
        return ans;
}
