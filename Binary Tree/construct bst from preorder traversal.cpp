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
    void inserttobst(TreeNode* ans, int key){
        if(ans->val>key){
            if(ans->left==NULL){
                TreeNode* extra=new TreeNode(key);
                ans->left=extra;
            }
            else{
                inserttobst(ans->left,key);
            }
        }
        else{
            if(ans->right==NULL){
                TreeNode* extra=new TreeNode(key);
                ans->right=extra;
            }
            else{
                inserttobst(ans->right,key);
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* ans=new TreeNode(preorder[0]);
        for(int i=1 ; i<preorder.size() ; i++){
            inserttobst(ans,preorder[i]);
        }
        return ans;
    }
};