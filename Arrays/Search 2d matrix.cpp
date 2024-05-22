class Solution {
public:
    bool findin(vector<int>& arr, int target){
        int start = 0, end = arr.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] < target)
                start = mid + 1;
            else if (arr[mid] == target)
                return true;
            else
                end = mid - 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        
        int rows = matrix.size(), cols = matrix[0].size();
        int start = 0, end = rows - 1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (matrix[mid][0] <= target && matrix[mid][cols - 1] >= target) {
                return findin(matrix[mid], target);
            } else if (matrix[mid][0] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }
};