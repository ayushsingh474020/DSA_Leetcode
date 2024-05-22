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
    vector<vector<long long int>> levelOrder(TreeNode* root) {
        vector<vector<long long int>> ans;
        if(root==NULL){
            return ans;
        }
        vector<long long int> extra;
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
        return ans;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<long long int>> extra=levelOrder(root);
        vector<double> ans;
        for(int i=0 ; i<extra.size() ; i++){
            double a=0;
            for(int j=0 ; j<extra[i].size() ; j++){
                a+=extra[i][j];
            }
            double b=extra[i].size();
            ans.push_back(a/b);
        }
        return ans;
    }
};