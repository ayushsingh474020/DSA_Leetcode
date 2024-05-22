class Solution {
public:
    int solverec(int n){
        if(n==0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        else if(n==2){
            return 1;
        }
        else{
            return solverec(n-1)+solverec(n-2)+solverec(n-3);
        }
    } 
    int solvemem(int n, vector<int> &dp){
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=solvemem(n-1,dp)+solvemem(n-2,dp)+solvemem(n-3,dp);
        return dp[n];
    }
    int solvetab(int n){
        vector<int> dp(n+1,0);
        dp[0]=0;
        if(n>0){
            dp[1]=1;
        }
        if(n>1){
            dp[2]=1;
        }
        for(int i=3 ; i<=n ; i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
    long long solveopt(int n){
        long long prev1=0;
        if(n==0){
            return prev1;
        }
        long long prev2=1;
        if(n==1){
            return prev2;
        }
        long long prev3=1;
         if(n==2){
            return prev3;
        }
        for(int i=3 ; i<=n ; i++){
            long long ans=prev1+prev2+prev3;
            prev1=prev2;
            prev2=prev3;
            prev3=ans;
        }
        return prev3;
    }
    int tribonacci(int n) {
        // int ans=solverec(n);
        // return ans;

        // vector<int> dp(n+1,-1);
        // dp[0]=0;
        // if(n>0){
        //     dp[1]=1;
        // }
        // if(n>1){
        //     dp[2]=1;
        // }
        // return solvemem(n,dp);

        // return solvetab(n);

        return solveopt(n);
    }
};