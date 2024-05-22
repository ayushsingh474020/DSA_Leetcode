class Solution {
public:
    int solverec(int m, int n, int i, int j){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>=m || j>=n){
            return 0;
        }
        return  solverec(m,n,i+1,j)+solverec(m,n,i,j+1);
    }
    int solvemem(int m, int n, int i, int j, vector<vector<int>> &dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j]=solvemem(m,n,i+1,j,dp)+solvemem(m,n,i,j+1,dp);
        return dp[i][j];
    }
    int solvetab(int m, int n){
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[m-1][n-1]=1;
        for(int i=m-1 ; i>=0 ; i--){
            for(int j=n-1 ; j>=0 ; j--){
                dp[i][j]=dp[i][j]+dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
    int uniquePaths(int m, int n) {
        // return solverec(m,n,0,0);

        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // return solvemem(m,n,0,0,dp);

        return solvetab(m,n);
    }
};