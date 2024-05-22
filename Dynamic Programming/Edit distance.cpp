class Solution {
public:
    int solve(string& a, string& b, int i, int j){
        // base case
        if(i == a.length())
            return (b.length() - j);

        if(j == b.length())
            return (a.length() - i);

        int ans = 0;

        if(a[i] == b[j])
            return solve(a, b, i+1, j+1);

        else
        {
            // insert
            int insertAns = 1 + solve(a, b, i, j+1);
            
            //delete
            int deleteAns = 1 + solve(a, b, i+1, j);
            
            // update
            int replaceAns = 1 + solve(a, b, i+1, j+1);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        
        return ans;
    }
    int solverec(string& s, string& t, int i, int j){
        if(i==s.size()){
            return t.size()-j;
        }
        if(j==t.size()){
            return s.size()-i;
        }
        int ans=0;
        if(s[i]==t[j]){
            return solverec(s,t,i+1,j+1);
        }
        else{
            // int mini=INT_MAX;
            int a=1+solverec(s,t,i+1,j);     //deletion in s
            int b=1+solverec(s,t,i+1,j+1);   //replacing character
            int c=1+solverec(s,t,i,j+1);     //insertion in s
            ans=min(a,min(b,c));
        }
        
        return ans;
    }
    int solvemem(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(i==s.size()){
            return t.size()-j;
        }
        if(j==t.size()){
            return s.size()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // int ans=0;
        if(s[i]==t[j]){
            return solvemem(s,t,i+1,j+1,dp);
        }
        // int mini=INT_MAX;
        int a=1+solvemem(s,t,i+1,j,dp);     //deletion in s
        int b=1+solvemem(s,t,i+1,j+1,dp);   //replacing character
        int c=1+solvemem(s,t,i,j+1,dp);     //insertion in s
        return dp[i][j]=min(a,min(b,c));
        // return dp[i][j];
        
        
    }
    int solvetab(string &s, string &t){
        vector<vector<int>> dp(s.size()+1, vector<int> (t.size()+1, 0));
        for(int i=0 ; i<s.size() ; i++){
            dp[i][t.size()]=s.size()-i;
        }
        for(int j=0 ; j<t.size() ; j++){
            dp[s.size()][j]=t.size()-j;
        }
        for(int i=s.size()-1 ; i>=0 ; i--){
            for(int j=t.size()-1 ; j>=0 ; j--){
                int ans=0;
                if(s[i]==t[j]){
                    ans=dp[i+1][j+1];
                }
                else{
                    int a=1+dp[i+1][j];
                    int b=1+dp[i+1][j+1];
                    int c=1+dp[i][j+1];
                    ans=min(a,min(b,c));
                }
                
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
    int minDistance(string s, string t) {
        // int ans=solverec(word1,word2,0,0);
        // return ans;

        // vector<vector<int>> dp(s.size()+1, vector<int> (t.size()+1, -1));
        //  int ans=solvemem(s,t,0,0,dp);
        //  return ans;

        return solvetab(s,t);
    }
};