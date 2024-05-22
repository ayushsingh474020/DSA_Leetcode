// class Solution {
// public:
//     vector<vector<int>> uni;
//     void solve(vector<vector<int>> &extra, int n){
//         uni.clear();
//         for(int i=0 ; i<extra.size() ; i++){
//             int max=extra[i][extra[i].size()-1];
//             for(int j=max+1 ; j<=n ; j++){
//                 extra[i].push_back(j);
//                 uni.push_back(extra[i]);
//                 extra[i].pop_back();
//             }
//         }
//     }
//     vector<vector<int>> combine(int n, int k) {
//         vector<vector<int>> extra;
//         for(int i=1 ; i<=n ; i++){
//             vector<int> extras;
//             extras.push_back(i);
//             extra.push_back(extras);
//         }
//         uni=extra;
//         for(int i=1 ; i<k ; i++){
//             extra=uni;
//             solve(extra,n);
//         }
//         return uni;
//     }
// };

class Solution {
private:
    // Recursive function to generate combinations of k elements from the range [1, n]
    void solve(int &n, int &k, vector<vector<int>>& ans, int ind, vector<int>& ds) {
        // Base case: If the combination size becomes equal to k, add it to the result and return
        if (ds.size() == k) {
            ans.push_back(ds);
            return;
        }
        // Generate combinations by selecting elements from ind to n
        for (int i = ind; i <= n; i++) {
            ds.push_back(i); // Include the current element in the combination
            solve(n, k, ans, i + 1, ds); // Recur to include the next element
            ds.pop_back(); // Backtrack by removing the last added element
        }
    }
public:
    // Function to generate all possible combinations of k elements from the range [1, n]
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans; // Vector to store the result (combinations)
        vector<int> ds; // Vector to store the current combination during the recursion
        // Call the solve function to generate all combinations
        solve(n, k, ans, 1, ds);
        return ans;
    }
};