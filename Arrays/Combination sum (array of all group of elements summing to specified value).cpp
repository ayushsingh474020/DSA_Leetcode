class Solution {
public:
    vector<vector<int>> ans;
    void solverec(vector<int> &nums,int i, int sum, int target, vector<int> &extra){
        if(i<nums.size()){
            extra.push_back(nums[i]);
            sum+=nums[i];
        }
        else{
            return;
        }
        if(target==sum){
            ans.push_back(extra);
        }
        else if(sum<target){
            for(int j=i ; j<nums.size() ; j++){
                solverec(nums,j,sum,target,extra);
            }
        }
        extra.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        reverse(candidates.begin(),candidates.end());
        for(int i=0 ; i<candidates.size() ; i++){
            vector<int> extra;
            solverec(candidates,i,0,target,extra);
        }
        return ans;
    }
};