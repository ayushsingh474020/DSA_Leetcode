class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
    deque<int> dq;
    for (int i = 0; i < nums.size(); i++) {
        // remove indices that are out of the current window
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        // remove indices with smaller values from the back
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
    }
};