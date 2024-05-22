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
    vector<TreeNode*> extra;
    void preorder(TreeNode* root){
        if(root!=NULL){
            extra.push_back(root);
            preorder(root->left);
            preorder(root->right);
        }
    }
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        preorder(root);
        for(int i=0 ; i<extra.size()-1 ; i++){
            extra[i]->left=NULL;
            extra[i]->right=extra[i+1];
        }
        extra[extra.size()-1]->left=NULL;
        extra[extra.size()-1]->right=NULL;
    }
};