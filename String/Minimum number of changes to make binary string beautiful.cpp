class Solution {
public:
    int solverec(string s, int i){
        if(i>=s.size()-1){
            return 0;
        }
        if(s[i]==s[i+1]){
            return solverec(s,i+2);
        }
        char extra=s[i];
        s[i]=s[i+1];
        int a=1+solverec(s,i+2);
        s[i]=extra;
        s[i+1]=extra;
        int b=1+solverec(s,i+2);
        return min(a,b);
        
    }
    int solvemem(string &s, int i, vector<int> &dp){
        if(i>=s.size()-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if(s[i]==s[i+1]){
            return solvemem(s,i+2,dp);
        }
        int extra=s[i];
        s[i]=s[i+1];
        int a=1+solvemem(s,i+2,dp);
        s[i]=extra;
        s[i+1]=extra;
        int b=1+solvemem(s,i+2,dp);
        dp[i]=min(a,b);
        return min(a,b);
    }
    int minChanges(string s) {
        // return solverec(s,0);
        
        vector<int> dp(s.size()+1, -1);
        return solvemem(s,0,dp);
    }
};