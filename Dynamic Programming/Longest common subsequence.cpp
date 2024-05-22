class Solution {
public:
    int solverec(string s1, string s2, int i, int j){
        if(i>s1.size()-1 || j>s2.size()-1){
            return 0;
        }
        if(s1[i]==s2[j]){
            return 1+solverec(s1,s2,i+1,j+1);
        }
        int incl = solverec(s1,s2,i+1,j);
        int excl = solverec(s1,s2,i,j+1);
        return max(incl,excl);

    }

    int memoization(string s1, string s2, int i, int j, vector<vector<int>> &dp){
        if(i>s1.size()-1 || j>s2.size()-1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return 1+memoization(s1,s2,i+1,j+1,dp);
        }
        int incl = memoization(s1,s2,i+1,j,dp);
        int excl = memoization(s1,s2,i,j+1,dp);
        dp[i][j]=max(incl,excl);
        return dp[i][j];
    }

    int tabulation(string s1, string s2){
        vector<vector<int>> dp(s1.size()+1,vector<int> (s2.size()+1,0));

        for(int i=s1.size()-1 ; i>=0 ; i--){
            for(int j=s2.size()-1 ; j>=0 ; j--){
                if(s1[i]==s2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }

        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // return solverec(text1,text2,0,0);

        // vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        // return memoization(text1,text2,0,0,dp);

        return tabulation(text1,text2);

    }
};