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
    int Findposition(vector<int> in ,int inorderStart , int inorderEnd , int element ,int  n){
        for(int i = inorderStart ; i<=inorderEnd ;i++){
            if(in[i]==element){
                return i ; 
            }
        }
        return -1 ;
    }
    TreeNode* solve(vector<int> in,vector<int> post, int &index ,int inorderStart , int inorderEnd , int n){
        if(index<0 || inorderStart>inorderEnd){
            return NULL ;
        }
        
        int element = post[index--] ; // At every interation index is increasing
        TreeNode* root  = new TreeNode(element); 
        int position  = Findposition(in , inorderStart , inorderEnd ,element, n);
        
        root->right = solve(in , post , index , position+1 , inorderEnd ,n);
        root->left = solve(in , post , index  , inorderStart , position-1 ,n);
        return root ;
        
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n=post.size();
        int postorderindex  = n-1 ;  //Pre order is NLR so First element is root .
        TreeNode* ans = solve(in , post , postorderindex , 0  , n-1 , n );
        return ans ;
    }
};