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
    pair<int,int> process(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> left=process(root->left);
        pair<int,int> right=process(root->right);
        int dia1=left.first;
        int dia2=right.first;
        int height=left.second+right.second+1;
        pair<int,int> ans;
        ans.first=max(height,max(dia1,dia2));
        ans.second=max(left.second,right.second)+1;
        return ans;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        return process(root).first-1;
    }
};