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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==NULL){
            return root;
        }
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            TreeNode* extra1=temp->left;
            TreeNode* extra2=temp->right;
            if(extra1!=NULL){
                q.push(extra1);
            }
            if(extra2!=NULL){
                q.push(extra2);
            }
            temp->left=extra2;
            temp->right=extra1;
        }
        return root;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return 1;
        }
        else if(p==NULL || q==NULL){
            return 0;
        }
        else{
            if(p->val!=q->val){
                return 0;
            }
            else{
                return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
            }
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return 1;
        }
        root->right=invertTree(root->right);
        return isSameTree(root->left,root->right);
    }
};