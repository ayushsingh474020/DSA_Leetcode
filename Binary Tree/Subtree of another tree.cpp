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
    bool solverec(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL){
            return true;
        }
        else if(p==NULL || q==NULL){
            return false;
        }
        else{
            if(p->val==q->val){
                return (solverec(p->left,q->left) && solverec(p->right,q->right));
            }
            else{
                return false;
            }
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solverec(p,q);
    }
    bool solve(TreeNode* root, TreeNode* subRoot){
        if(root!=NULL){
            if(isSameTree(root,subRoot)){
                return true;
            }
            return (solve(root->left,subRoot) || solve(root->right,subRoot));
        }
        else if(root==NULL && subRoot==NULL){
            return true;
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve(root,subRoot);
    }
};