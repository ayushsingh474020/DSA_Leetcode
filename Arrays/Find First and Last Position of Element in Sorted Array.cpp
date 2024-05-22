class Solution {
public: 
    int start=pow(2,31)-1;
    int end=0;
    void process(vector<int>& nums, int target, int i, int j){
        if(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target){
                if(start>mid){
                    start=mid;
                }
                if(end<mid){
                    end=mid;
                }
                process(nums,target,i,mid-1);
                process(nums,target,mid+1,j);
            }
            else if(nums[mid]>target){
                return process(nums,target,i,mid-1);
            }
            else{
                return process(nums,target,mid+1,j);
            }
            
        }
    } 
    vector<int> searchRange(vector<int>& nums, int target) {
        process(nums,target,0,nums.size()-1);
        vector <int> ans;
        ans.push_back(start);
        ans.push_back(end);
        if(ans[0]>ans[1]){
            return {-1,-1};
        }
        return ans;
    }
};