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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> tempo;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        Q.push(NULL);

        while(!Q.empty()) {
            TreeNode* temp = Q.front();
            Q.pop();

            if(temp == NULL) {
                ans.push_back(tempo);
                tempo.clear();

                if(!Q.empty()) {
                    Q.push(NULL);
                }
            } else {
                tempo.push_back(temp->val);
                // cout << temp->data << " ";

                if(temp->left) {
                    Q.push(temp->left);
                }

                if(temp->right) {
                    Q.push(temp->right);
                }
            }
        }
        for(int i=0 ; i<ans.size() ; i++){
            if(i%2!=0){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};