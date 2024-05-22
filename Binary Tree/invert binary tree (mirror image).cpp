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
};