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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* p1=root;
        TreeNode* newer=new TreeNode(val);
        if(p1==NULL){
            return newer;
        }
        while(root!=NULL){
            if(val<root->val){
                if(root->left==NULL){
                    root->left=newer;
                    break; 
                }
                else{
                    root=root->left;
                }
                
            }
            else if(val>root->val){
                if(root->right==NULL){
                    root->right=newer;
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return p1;
    }
};