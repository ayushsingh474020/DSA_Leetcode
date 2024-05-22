class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        int count=0;
        int indice;
        vector <int> ans;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==0){
                count++;
                indice=i;
            }
        }
        if(count>1){
            for(int i=0 ; i<nums.size() ; i++){
                ans.push_back(0);
            }
            
        }
        else if(count==1){
            for(int i=0 ; i<nums.size() ; i++){
                if(nums[i]!=0){
                    product*=nums[i];
                }
            }
            for(int i=0 ; i<nums.size() ; i++){
                if(i==indice){
                    ans.push_back(product);
                }
                else{
                    ans.push_back(0);
                }
            }
        }
        else{
            for(int i=0 ; i<nums.size() ; i++){
                product*=nums[i];
            }
            for(int i=0 ; i<nums.size() ; i++){
                ans.push_back(product/nums[i]);
            }
        }
        
        return ans;
    }
};