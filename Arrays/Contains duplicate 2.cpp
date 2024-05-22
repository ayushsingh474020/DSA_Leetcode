class Solution {
public:
    int mod(int a, int b){
        if(a>=b){
            return a-b; 
        }
        else{
            return b-a;
        }
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0 ; i<n ; i++){
            auto it=lower_bound(nums.begin()+i+1,nums.end(),nums[i]);
            if((*it)==nums[i]){
                if(mod(i,it-nums.begin())<=k){
                    return 1;
                }
            }
            
        }
        return 0;
    }
};