/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> ancestors;
    // vector<int> ancestors;
    int flag=0;
    void process(TreeNode* root,TreeNode* item){
        if(root!=NULL && flag==0){
            ancestors.push_back(root);
            if(root==item){
                flag=1;
            }
            process(root->left,item);
            process(root->right,item);
            if(flag==0){
                ancestors.pop_back();
            }
        }
        // return ancestors;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // TreeNode* Root=root;
        process(root,p);
        vector<TreeNode*> pancestors=ancestors;
        ancestors.clear();
        flag=0;
        process(root,q);
        vector<TreeNode*> qancestors=ancestors;
        ancestors.clear();
        // for(int i=0 ; i<pancestors.size() ; i++){
        //     cout<<pancestors[i]->val<<" ";
        // }
        // cout<<endl;
        // for(int i=0 ; i<qancestors.size() ; i++){
        //     cout<<qancestors[i]->val<<" ";
        // }
        if(pancestors.size()==1){
            return p;
        }
        else if(qancestors.size()==1){
            return q;
        }
        else{
            int i=0;
            int j=0;
            while(i<pancestors.size() && j<qancestors.size()){
                if(pancestors[i]==qancestors[j]){
                    i++;
                    j++;
                }
                else{
                    return pancestors[i-1];
                }
            }
            if(i>=pancestors.size()){
                return p;
            }
            if(j>=qancestors.size()){
                return q;
            }
        }
        return root;
    }
};