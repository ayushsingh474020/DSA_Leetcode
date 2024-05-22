class Solution {
public:
    int solverec(vector<vector<int>>& triangle, int i, int j){
        if(i>=triangle.size()){
            return 0;
        }
        int a=solverec(triangle,i+1,j);
        int b=solverec(triangle,i+1,j+1);
        return triangle[i][j]+min(a,b);
    }
    int solvemem(vector<vector<int>>& triangle, int i, int j, vector<vector<int>> &dp){
        if(i>=triangle.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=solvemem(triangle,i+1,j,dp);
        int b=solvemem(triangle,i+1,j+1,dp);
        dp[i][j]=triangle[i][j]+min(a,b);
        return triangle[i][j]+min(a,b);
    }
    int solvetab(vector<vector<int>>& triangle){
        int n=triangle.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        dp[0][0]=triangle[0][0];
        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<n ; j++){
                dp[i][j]=dp[i-1][j-1]+min(triangle[i][j-1],triangle[i][j]);
            }
        }
        return dp[n-1][n-1];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // int ans=solverec(triangle,0,0);
        // return ans;

        // int n=triangle.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        // int ans=solvemem(triangle,0,0,dp);
        // return ans;

        return solvetab(triangle);
    }
};