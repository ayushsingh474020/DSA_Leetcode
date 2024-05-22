class Solution {
public:
    vector<vector<int>> subset;

    void generate(vector<int> &prev, int i, vector<int> &nums){
        if(i==nums.size()){
            subset.push_back(prev);
            return;
        }

        generate(prev,i+1,nums);

        prev.push_back(nums[i]);
        generate(prev,i+1,nums);
        prev.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> extra;
        generate(extra,0,nums);
        return subset;
    }
};