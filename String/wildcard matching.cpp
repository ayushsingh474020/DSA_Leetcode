class Solution {
public:
    bool solverec(string s,string p,int i,int j){
        if(i==s.size() && j==p.size()){
            return true;
        }
        if(i==s.size()+1 || j==p.size()){
            return false;
        }
        if(s[i]==p[j] || p[j]=='?'){
            return solverec(s,p,i+1,j+1);
        }
        if(p[j]=='*'){
            return ((solverec(s,p,i+1,j) || solverec(s,p,i+1,j+1)) || solverec(s,p,i,j+1));
        }
        return false;
    }

    bool memoization(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i==s.size() && j==p.size()){
            return true;
        }
        if(i==s.size()+1 || j==p.size()){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=memoization(s,p,i+1,j+1,dp);
            return dp[i][j];
        }
        if(p[j]=='*'){
            dp[i][j]=((memoization(s,p,i+1,j,dp)|| memoization(s,p,i+1,j+1,dp)) || memoization(s,p,i,j+1,dp));
            return dp[i][j];
        }
        dp[i][j]=0;
        return false;
    }

    bool tabulation(string s, string p, int i, int j){
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,0));

        for(int i=0 ; i<dp.size() ; i++){
            for(int j=0 ; j<dp[0].size() ; j++){
                if(i==s.size() && j==p.size()){
                    dp[i][j]=1;
                }
            }
        }

        for(int i=dp.size()-2 ; i>=0 ; i--){
            for(int j=dp[0].size()-2 ; j>=0 ; j--){
                if(s[i]==p[j] || p[j]=='?'){
                    dp[i][j]=dp[i+1][j+1];
                }
                if(p[j]=='*'){
                    dp[i][j]=(dp[i+1][j] || dp[i+1][j+1] || dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
    }

    bool isMatch(string s, string p) {
        bool flag=false;
        for(int i=0 ; i<p.size() ; i++){
            if(p[i]!='*'){
                flag=true;
                break;
            }
        }
        if(flag==false && p.size()>0){
            return true;
        }
        // return solverec(s,p,0,0);

        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return memoization(s,p,0,0,dp);

        // return tabulation(s,p,0,0);
    }
};