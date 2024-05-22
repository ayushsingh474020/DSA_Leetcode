class Solution {
public:
    vector<int> extra;
    vector<int> extra1;
    Solution(vector<int>& nums) {
        extra=nums;
        extra1=nums;
    }
    
    vector<int> reset() {
        return extra1;
    }
    
    vector<int> shuffle() {
        next_permutation(extra.begin(),extra.end());
        return extra;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */