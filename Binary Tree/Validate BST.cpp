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
    void solverec(TreeNode* root, long long int &prev, bool &flag){
        if(root!=NULL){
            solverec(root->left,prev,flag);
            if(flag==true){
                if(root->val<=prev){
                    flag=false;
                }
            }
            prev=root->val;
            solverec(root->right,prev,flag);
        }
    }
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        long long int prev= -9223372036854775807;
        bool flag=true;
        solverec(root,prev,flag);
        return flag;
    }
};