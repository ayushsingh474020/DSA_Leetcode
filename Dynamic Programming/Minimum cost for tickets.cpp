class Solution {
public:
    int solverec(vector<int> days, vector<int> costs, int x){
        if(x>=days.size()){
            return 0;
        }
        int mincost=INT_MAX;
        for(int i=0 ; i<3 ; i++){
            int ans;
            if(i==0){
                ans=solverec(days,costs,x+1);
            }
            else if(i==1){
                auto it=lower_bound(days.begin(),days.end(),days[x]+7);
                if(it!=days.end()){
                    int indi=it-days.begin();
                    ans=solverec(days,costs,indi);
                }
                else{
                    ans=solverec(days,costs,days.size());
                }
                
            }
            else if(i==2){
                auto it=lower_bound(days.begin(),days.end(),days[x]+30);
                if(it!=days.end()){
                    int indi=it-days.begin();
                    ans=solverec(days,costs,indi);
                }
                else{
                    ans=solverec(days,costs,days.size());
                }
            }
            mincost=min(mincost,ans+costs[i]);
        }
        return mincost;
    }
    int solvemem(vector<int> days, vector<int> costs, int x, vector<int> &dp){
        if(x>=days.size()){
            return 0;
        }
        if(dp[x]!=-1){
            return dp[x];
        }
        int mincost=INT_MAX;
        for(int i=0 ; i<3 ; i++){
            int ans;
            if(i==0){
                ans=solvemem(days,costs,x+1,dp);
            }
            else if(i==1){
                auto it=lower_bound(days.begin(),days.end(),days[x]+7);
                if(it!=days.end()){
                    int indi=it-days.begin();
                    ans=solvemem(days,costs,indi,dp);
                }
                else{
                    ans=solvemem(days,costs,days.size(),dp);
                }
                
            }
            else if(i==2){
                auto it=lower_bound(days.begin(),days.end(),days[x]+30);
                if(it!=days.end()){
                    int indi=it-days.begin();
                    ans=solvemem(days,costs,indi,dp);
                }
                else{
                    ans=solvemem(days,costs,days.size(),dp);
                }
            }
            
            mincost=min(mincost,ans+costs[i]);
        }
        dp[x]=mincost;
        return mincost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // int ans=solverec(days,costs,0);
        // return ans;

        vector<int> dp(days.size()+1,-1);
        int ans=solvemem(days,costs,0,dp);
        return ans;
    }
};