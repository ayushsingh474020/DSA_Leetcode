class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> extra;
        int i=0 ; 
        int n=nums.size();
        while(i<n){
            int count1=0;
            int count0=0;
            while(nums[i]==1){
                i++;
                count1++;
                if(i>=n){
                    break;
                }
            }
            extra.push_back(count1);
            if(i>=n){
                break;
            }
            while(nums[i]==0){
                i++;
                count0++;
                if(i>=n){
                    break;
                }
            }
            extra.push_back(count0);
            if(i>=n){
                break;
            }
        }
        for(int i=0 ; i<extra.size() ; i++){
            cout<<extra[i]<<" ";
        }
        i=1;
        int ans=0;
        int count=0;
        while(i<extra.size()){
            if(extra[i]==1){
                if(i-1>=0){
                    count+=extra[i-1];
                }
                if(i+1<extra.size()){
                    count+=extra[i+1];
                }
            }
            else if(extra[i]>1){
                if(i-1>=0){
                    count=extra[i-1];
                }
                if(i+1<extra.size()){
                    if(extra[i+1]>count){
                        count=extra[i+1];
                    }
                }
            }
            if(count>ans){
                ans=count;
            }
            count=0;
            i+=2;
        }
        if(extra.size()==1){
            return extra[0]-1;
        }
        return ans;
    }
};