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
    int maxlength=0;
    
    void preorder(TreeNode* &root, map<pair<TreeNode*,int>,int> &m){
        if(root!=NULL){
            maxlength=max(maxlength,max(check(root,0,m),check(root,1,m)));
            preorder(root->left,m);
            preorder(root->right,m);
        }
    }
    int check(TreeNode* &root, int dirn, map<pair<TreeNode*,int>,int> &m){
        if(root==NULL){
            return 0;
        }
        if(m.find({root,dirn})!=m.end()){
            return m[{root,dirn}];
        }
        if(dirn==0){
            m[{root,0}]=1+check(root->right,1,m);
            return m[{root,0}];
        }
        else{
            m[{root,1}]=1+check(root->left,0,m);
            return m[{root,1}];
        }
    }
    int longestZigZag(TreeNode* root) {
        // inorder(root);
        // vector<int> dp(n+1,-1);
        map<pair<TreeNode*,int>,int> m;
        preorder(root,m);
        return maxlength-1;
    }
};