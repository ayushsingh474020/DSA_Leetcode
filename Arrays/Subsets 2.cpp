class Solution {
public:
    set<vector<int>> subset;

    void generate(vector<int> &prev, int i, vector<int> &nums){
        if(i==nums.size()){
            subset.insert(prev);
            return;
        }

        generate(prev,i+1,nums);

        prev.push_back(nums[i]);
        generate(prev,i+1,nums);
        prev.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> extra;
        generate(extra,0,nums);
        // return subset;
        vector<vector<int>> ans;
        for(auto it=subset.begin() ; it!=subset.end() ; it++){
            ans.push_back(*it);
        }
        return ans;
    }
};