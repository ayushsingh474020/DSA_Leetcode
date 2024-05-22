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
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*> s;
        TreeNode* ptr=root;
        s.push(root);
        while(!s.empty()){
            if(ptr->left!=NULL){
                ptr=ptr->left;
                TreeNode* extra=s.top();
                extra->left=NULL;
                s.push(ptr);
                continue;
            }
            else if(ptr->right!=NULL){
                ptr=ptr->right;
                TreeNode* extra=s.top();
                extra->right=NULL;
                s.push(ptr);
                continue;
            }
            else{
                ans.push_back(ptr->val);
                s.pop();
                if(!s.empty()){
                    ptr=s.top();
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};