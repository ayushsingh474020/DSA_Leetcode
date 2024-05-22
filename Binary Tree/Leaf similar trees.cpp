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
    vector<int> leaf1;
    vector<int> leaf2;
    void inorder1(TreeNode* root){
        if(root!=NULL){
            if(root->left==NULL && root->right==NULL){
                leaf1.push_back(root->val);
            }
            inorder1(root->left);
            inorder1(root->right);
        }
        else{
            return ;
        }
        
    }
    void inorder2(TreeNode* root){
        if(root!=NULL){
            if(root->left==NULL && root->right==NULL){
                leaf2.push_back(root->val);
            }
            inorder2(root->left);
            inorder2(root->right);
        }
        else{
            return;
        }
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        inorder1(root1);
        inorder2(root2);
        for(int i=0 ; i<leaf1.size() ; i++){
            cout<<leaf1[i]<<" ";
        }
        cout<<endl;
        for(int i=0 ; i<leaf2.size() ; i++){
            cout<<leaf2[i]<<" ";
        }
        if(leaf1==leaf2){
            return true;
        }
        return false;
    }
};