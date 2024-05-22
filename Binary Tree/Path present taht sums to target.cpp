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
    vector<int> nodes;
    int sum=0;
    bool ans=false;
    bool hasPathSum(TreeNode* root, int targetSum){
        if(root!=NULL){
            nodes.push_back(root->val);
            sum+=root->val;
            if(root->left==NULL && root->right==NULL){
                if(sum==targetSum){
                    cout<<root->val<<" ";
                    ans=true;
                }
                // else{
                //     sum-=nodes[nodes.size()-1];
                //     nodes.pop_back();
                // }
            }
            hasPathSum(root->left,targetSum);
            hasPathSum(root->right,targetSum);
            sum-=nodes[nodes.size()-1];
            nodes.pop_back();
        }
        return ans;
        // return true;
    }
};