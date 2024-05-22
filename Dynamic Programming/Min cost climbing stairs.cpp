class Solution {
public:
    int processrec(vector<int> cost, int i){
        if(i>cost.size()-1){
            return 0;
        }
        if(i==cost.size()-1){
            return cost[i];
        }
        return cost[i]+min(processrec(cost,i+1),processrec(cost,i+2));
    }
    int processmem(vector<int> cost, int i, vector<int>& dp){
        if(i>cost.size()-1){
            return 0;
        }
        if(i==cost.size()-1){
            return cost[i];
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i]=cost[i]+min(processmem(cost,i+1,dp),processmem(cost,i+2,dp));
        return dp[i];
    }
    int processtab(vector<int> cost){
        vector<int> dp(cost.size()+1,INT_MAX);

        dp[cost.size()]=cost[cost.size()-1];

        for(int i=cost.size()-1 ; i>=1 ; i--){
            if(i+2<=cost.size()){
                dp[i]=min(dp[i+1],dp[i+2])+cost[i-1];
            }
            else{
                dp[i]=cost[i-1];
            }
            
        }

        for(int i=0 ; i<=cost.size() ; i++){
            cout<<dp[i]<<" ";
        }

        return min(dp[1],dp[2]);
    }
    int spaceopt(vector<int> cost){
        int next2=0;
        int next1=cost[cost.size()-1];

        for(int i=cost.size()-1 ; i>=1 ; i--){
            int cur=cost[i-1]+min(next2,next1);
            next2=next1;
            next1=cur;
        }
        return min(next1,next2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // return min(processrec(cost,0),processrec(cost,1));

        // vector<int> dp(cost.size()+1,-1);
        // return min(processmem(cost,0,dp),processmem(cost,1,dp));

        // return processtab(cost);

        return spaceopt(cost);
    }
};