class Solution {
public:
    // #define MOD 1000000007
int process(int n, int i){
	if(i==n){
		return 1;
	}
	if(i>n){
		return 0;
	}
	return process(n,i+1)+process(n,i+2);
}
int process(int n,vector<int> &dp){
	if(n<0){
		return 0;
	}
	if(n<=1){
		return 1;
	}
	// if(n==2){
	// 	return 2;
	// }
	if(dp[n]!=-1){
		return dp[n];
	}
	dp[n]=process(n-1,dp)+process(n-2,dp);
	return dp[n];
}
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int ans=process(n,dp);
        return ans;
    }
};