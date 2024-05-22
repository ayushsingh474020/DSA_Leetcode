class Solution {
public:
    bool check_duplicate(string extra){
        vector<int> alpha(26,0);

        for(int i=0 ; i<extra.size() ; i++){
            alpha[int(extra[i])-97]++;
        }

        for(int i=0 ; i<26 ; i++){
            if(alpha[i]>1){
                return true;
            }
        }
        return false;
    }
    int maxLength(vector<string>& nums) {
        vector<vector<string>> answer;
        int ans=INT_MIN;
        int n=nums.size();

        for(int i=0 ; i<nums.size() ; i++){
            if(check_duplicate(nums[i])){
                nums[i]="";
            }
        }

        for(int i=0 ; i<(1<<n) ; i++){
            int len=0;
            int flag=0;
            vector<int> extra(26,0);
            vector<string> extras;
            for(int j=0 ; j<n ; j++){
                if((1<<j) & i){
                    for(int x=0 ; x<nums[j].size() ; x++){
                        if(extra[int(nums[j][x]-97)]>0){
                            flag=1;
                            break;
                        }
                    }
                    if(flag!=1){
                        extras.push_back(nums[j]);
                        for(int x=0 ; x<nums[j].size() ; x++){
                            extra[int(nums[j][x]-97)]++;
                        }
                        len+=nums[j].size();
                    }
                }
            }
            ans=max(ans,len);
            
        }

        return ans;
        
    }
};