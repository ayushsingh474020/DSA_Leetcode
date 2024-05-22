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
    TreeNode* minival(TreeNode* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val==key){
            //0 child
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }

            //1 chid 
            //left child
            if(root->right==NULL && root->left!=NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }

            //right child
            if(root->right!=NULL && root->left==NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }


            //2 childs
            if(root->right!=NULL && root->left!=NULL){
                int mini=minival(root->right)->val;
                root->val=mini;
                root->right=deleteNode(root->right,mini);
            }

        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{
            root->left=deleteNode(root->left,key);
        }
        return root;

    }
};