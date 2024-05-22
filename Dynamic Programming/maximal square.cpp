class Solution {
public:
    int solverec(vector<vector<char>> &mat, int i, int j, int &maxi){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        int diagonal=solverec(mat,i+1,j+1,maxi);
        int right=solverec(mat,i,j+1,maxi);
        int down=solverec(mat,i+1,j,maxi);
        if(mat[i][j]=='1'){
            int ans=1+min(diagonal,min(right,down));
            maxi=max(ans,maxi);
            return ans;
        }
        else{
            return 0;
        }
        
    }
    int solvemem(vector<vector<char>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int diagonal=solvemem(mat,i+1,j+1,maxi,dp);
        int right=solvemem(mat,i,j+1,maxi,dp);
        int down=solvemem(mat,i+1,j,maxi,dp);
        if(mat[i][j]=='1'){
            dp[i][j]=1+min(diagonal,min(right,down));
            maxi=max(dp[i][j],maxi);
            // dp[i][j]=ans;
            return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
    }
    int maximalSquare(vector<vector<char>>& mat) {
        // int maxi=0;
        // solverec(mat,0,0,maxi);
        // return maxi*maxi;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int maxi=0;
        int ans=solvemem(mat,0,0,maxi,dp);
        return maxi*maxi;
    
    }
};