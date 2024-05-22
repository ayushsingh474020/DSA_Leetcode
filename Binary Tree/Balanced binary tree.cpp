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
    bool ans=false;
    int flag=0;
    int solverec(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(solverec(root->left),solverec(root->right));
    }
    int maxDepth(TreeNode* root) {
        return solverec(root);
    }
    bool solve(TreeNode* root){
        if(root==NULL){
            return true;
        }
        int height1=maxDepth(root->left);
        int height2=maxDepth(root->right);
        if(abs(height1-height2)<=1){
            return true;
        }
        return false;
    }
    void preorder(TreeNode* root){
        if(root!=NULL){
            ans=solve(root);
            if(ans==false){
                flag=1;
                return;
            }
            if(flag==0){
                preorder(root->left);
                preorder(root->right);
            }
        }
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        preorder(root);
        return ans;
    }
};