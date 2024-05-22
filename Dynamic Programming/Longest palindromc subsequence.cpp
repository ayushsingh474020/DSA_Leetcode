class Solution {
public:
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
    int longestPalindromeSubseq(string s) {
        string newer = s;
        reverse(s.begin(),s.end());
        return tabulation(newer,s);
    }
};