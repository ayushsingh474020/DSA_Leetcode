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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> ans1;
        if(root==NULL){
            return ans1;
        }
        vector<int> extra;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                ans.push_back(extra);
                extra.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                extra.push_back(temp->val);
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            
            }
        }
        
        for(int i=0 ; i<ans.size() ; i++){
            ans1.push_back(ans[i][ans[i].size()-1]);
        }
        return ans1;
    }
};