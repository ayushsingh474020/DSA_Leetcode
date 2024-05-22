class Solution {
public:
    bool can_be_completed(string p, int j){
        while(j<p.size()){
            if(p[j]!='*' && j+1<p.size() && p[j+1]=='*'){
                j+=2;
            }
            else if(p[j]=='*'){
                j+=1;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool solverec(string s,string p,int i,int j){
        if(i==s.size() && j==p.size()){
            return true;
        }
        if(i==s.size()){
            if(can_be_completed(p,j) ){
                return true;
            }
            else{
                return false;
            }
        }
        if(s[i]==p[j] || p[j]=='.'){
            bool ans1=false;
            bool ans2=false;
            if(j+1<p.size() && p[j+1]=='*'){
                ans1=solverec(s,p,i,j+2);
            }
            ans2=solverec(s,p,i+1,j+1);
            return ans1 || ans2;
        }
        if(p[j]=='*'){
            bool ans1=false;
            bool ans2=false;
            bool ans3=false;
            if(s[i]==p[j-1] || p[j-1]=='.'){
                ans1=solverec(s,p,i+1,j);
                ans2=solverec(s,p,i+1,j+1);
            }
            ans3=solverec(s,p,i,j+1);
            return (ans1 || ans2 || ans3);
        }
        if(s[i]!=p[j] && j+1<p.size() && p[j+1]=='*'){
            return solverec(s,p,i,j+2);
        }
        return false;
    }
    bool memoization(string &s,string &p,int i,int j,vector<vector<int>> &dp){
        if(i==s.size() && j==p.size()){
            return true;
        }
        if(i==s.size()){
            if(can_be_completed(p,j)){
                return true;
            }
            else{
                return false;
            }
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==p[j] || p[j]=='.'){
            bool ans1=false;
            bool ans2=false;
            if(j+1<p.size() && p[j+1]=='*'){
                ans1=memoization(s,p,i,j+2,dp);
            }
            ans2=memoization(s,p,i+1,j+1,dp);
            dp[i][j]=ans1 || ans2;
            return dp[i][j];
        }
        if(p[j]=='*'){
            bool ans1=false;
            bool ans2=false;
            bool ans3=false;
            if(s[i]==p[j-1] || p[j-1]=='.'){
                ans1=memoization(s,p,i+1,j,dp);
                ans2=memoization(s,p,i+1,j+1,dp);
            }
            ans3=memoization(s,p,i,j+1,dp);
            dp[i][j]=(ans1 || ans2 || ans3);
            return dp[i][j];
        }
        if(s[i]!=p[j] && j+1<p.size() && p[j+1]=='*'){
            dp[i][j]=memoization(s,p,i,j+2,dp);
            return dp[i][j];
        }
        dp[i][j]=false;
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        // return solverec(s,p,0,0);

        vector<vector<int>>dp (s.size()+1,vector<int>(p.size()+1,-1));
        return memoization(s,p,0,0,dp);
    }
};