class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int flag=0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]<0){
                flag=1;
                nums[i]=50+nums[i];
            }
        }
        vector<int> extra=nums;
        next_permutation(nums.begin(),nums.end());
        vector<vector<int>> ans;
        ans.push_back(extra);
        while(extra!=nums){
            ans.push_back(nums);
            next_permutation(nums.begin(),nums.end());
        }
        for(int i=0 ; i<ans.size() ; i++){
            for(int j=0 ; j<ans[i].size() ; j++){
                if(ans[i][j]>10){
                    ans[i][j]-=50;
                }
            }
        }

        return ans;
    }
};