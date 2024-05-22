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
    void solverec(TreeNode* root, int &ans, int &extra){
        // static int extra=100000;
        if(root!=NULL){
            solverec(root->left,ans,extra);
            // cout<<root->data<<endl;
            if(ans>abs(extra-root->val)){
                ans=abs(extra-root->val);
            }
            extra=root->val;
            solverec(root->right,ans,extra);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int extra=100000;
        int ans=100000;
        solverec(root,ans,extra);
        return ans;
    }
};