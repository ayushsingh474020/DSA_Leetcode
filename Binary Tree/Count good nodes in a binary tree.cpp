/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    vector<int> maxes;
    int max=-10001;
    // int flag=0;
    int goodNodes(TreeNode* root) {
        if(root!=NULL){
            if(root->val>=max){
                max=root->val;
                ans++;
                maxes.push_back(max);
            }
            goodNodes(root->left);
            goodNodes(root->right);
            if(maxes[maxes.size()-1]==root->val){
                maxes.pop_back();
                if(maxes.size()>0){
                    max=maxes[maxes.size()-1];
                }
            }  
        }
        return ans;
    }
};