class Solution {
public:
    unordered_map<int,int> m;
    int solverec(string s, int i){
        if(i==s.size()-1 && s[i]!='0'){
            return 1;
        }
        if(i==s.size()-1 && s[i]==0){
            return 0;
        }
        if(i==s.size()-2){
            int tenth = int(s[i])-48;
            int oneth = int(s[s.size()-1])-48;
            int expr = tenth*10+oneth;
            return m[expr];
        }
        int a=0;
        int b=0;
        if(s[i]!='0'){
            a=solverec(s,i+1);
        }
        int tenth = int(s[i])-48;
        int oneth = int(s[i+1])-48;
        int expr = tenth*10+oneth;
        if(expr>=10 && expr<=26){
            b=solverec(s,i+2);
        }
        return a+b;
    }

    int memoization(string s, int i, vector<int> &dp){
        if(i==s.size()-1 && s[i]!='0'){
            return 1;
        }
        if(i==s.size()-1 && s[i]==0){
            return 0;
        }
        if(i==s.size()-2){
            int tenth = int(s[i])-48;
            int oneth = int(s[s.size()-1])-48;
            int expr = tenth*10+oneth;
            return m[expr];
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int a=0;
        int b=0;
        if(s[i]!='0'){
            a=memoization(s,i+1,dp);
        }
        int tenth = int(s[i])-48;
        int oneth = int(s[i+1])-48;
        int expr = tenth*10+oneth;
        if(expr>=10 && expr<=26){
            b=memoization(s,i+2,dp);
        }
        dp[i]=a+b;
        return dp[i];
    }

    int tabulation(string s){
        vector<int> dp(s.size()+1,0);

        if(s.size()==1 && s[s.size()-1]!='0'){
            return 1;
        }

        if(s.size()==1 && s[s.size()-1]=='0'){
            return 0;
        }

        if(s[s.size()-1]=='0'){
            dp[s.size()-1]=0;
        }
        if(s[s.size()-1]!='0'){
            dp[s.size()-1]=1;
        }
        int tenth = int(s[s.size()-2])-48;
        int oneth = int(s[s.size()-1])-48;
        int expr = tenth*10+oneth;
        dp[s.size()-2]=m[expr];

        for(int i=s.size()-3 ; i>=0 ; i--){
            int a=0;
            int b=0;
            if(s[i]!='0'){
                a=dp[i+1];
            }
            int tenth = int(s[i])-48;
            int oneth = int(s[i+1])-48;
            int expr = tenth*10+oneth;
            if(expr>=10 && expr<=26){
                b=dp[i+2];
            }
            dp[i]=a+b;
        }
        return dp[0];

    }

    int spaceopt(string s){
        int last2 = 0;
        if(s[s.size()-1]!='0'){
            last2 = 1;
        }
        if(s.size()==1){
            return last2;
        }
        int last1=0;
        int tenth = int(s[s.size()-2])-48;
        int oneth = int(s[s.size()-1])-48;
        int expr = tenth*10+oneth;
        last1 = m[expr];
        if(s.size()==2){
            return last1;
        }



        for(int i=s.size()-3 ; i>=0 ; i--){
            int a=0;
            int b=0;
            if(s[i]!='0'){
                a=last1;
            }
            int tenth = int(s[i])-48;
            int oneth = int(s[i+1])-48;
            int expr = tenth*10+oneth;
            if(expr>=10 && expr<=26){
                b=last2;
            }
            int cur = a+b;
            last2=last1;
            last1=cur;
        }
        return last1;
    }

    int numDecodings(string s) {
        
        for(int i=10 ; i<100 ; i++){
            if(i>=10 && i<=26){
                if(i%10==0){
                    m[i]=1;
                }
                else{
                    m[i]=2;
                }
            }
            else{
                if(i%10!=0){
                    m[i]=1;
                }
                else{
                    m[i]=0;
                }
            }
        }
        // return solverec(s,0);

        // vector<int> dp(s.size()+1,-1);
        // return memoization(s,0,dp);

        // return tabulation(s);

        return spaceopt(s);
    }
};