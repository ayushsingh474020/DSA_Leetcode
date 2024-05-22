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
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> extra;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                ans.push_back(extra);
                if(!q.empty()){
                    q.push(NULL);
                }
                extra.clear();
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
        int max=-100000,maxindi=1;
        for(int i=0 ; i<ans.size() ; i++){
            if(accumulate(ans[i].begin(),ans[i].end(),0)>max){
                max=accumulate(ans[i].begin(),ans[i].end(),0);
                maxindi=i+1;
            }
        }
        return maxindi;
    }
};