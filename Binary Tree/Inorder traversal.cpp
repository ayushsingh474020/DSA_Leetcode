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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL){
            return ans;
        }
        TreeNode* ptr=root;
        stack<TreeNode*> s;
        s.push(ptr);
        while(!s.empty()){
            if(ptr->left!=NULL){
                ptr=ptr->left;
                TreeNode* extra=s.top();
                extra->left=NULL;
                s.push(ptr);
                continue;
            }
            else{
                if(ptr->val!=-101){
                    // cout<<ptr->data<<" ";
                    ans.push_back(ptr->val);
                    ptr->val=-101;
                }
                if(ptr->right!=NULL){
                    ptr=ptr->right;
                    TreeNode* extra=s.top();
                    extra->right=NULL;
                    s.push(ptr);
                    continue;
                }
                else{
                    s.pop();
                    if(!s.empty()){
                        ptr=s.top();
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};