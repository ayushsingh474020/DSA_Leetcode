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
    // bool ans=false;
    vector<int> sums;
    // int power=0;
    void hasPathSum(TreeNode* root){
        if(root!=NULL){
            nodes.push_back(root->val);
            sum=sum*10;
            sum+=root->val;
            if(root->left==NULL && root->right==NULL){
                sums.push_back(sum);
            }
            hasPathSum(root->left);
            hasPathSum(root->right);
            sum-=nodes[nodes.size()-1];
            sum/=10;
            nodes.pop_back();
        }
        // return ans;
        // return true;
    }
    int sumNumbers(TreeNode* root) {
        hasPathSum(root);
        cout<<sums.size()<<" ";
        return accumulate(sums.begin(),sums.end(),0);
    }
};