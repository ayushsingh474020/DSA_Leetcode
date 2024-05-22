class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> ans;
        for(int i=0 ; i<nums.size() ; i++){
            if((nums[i]-1)!=i){
                if(i==nums[i]-1){
                    int c=nums[i];
                    nums[i]=nums[nums[i]-1];
                    nums[nums[i]-1]=c;
                }
                else{
                    ans.push_back(nums[i]);
                }
            }
           
        }
        
        return ans;
    }   
};