/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<Node*> ans;
        if(root==NULL){
            return root;
        }
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(temp==NULL){
                ans.push_back(NULL);
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                ans.push_back(temp);
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            
            }
        }
        for(int i=0 ; i<ans.size() ; i++){
           if(ans[i]!=NULL){
               cout<<ans[i]->val<<" ";
           }
           else{
               cout<<"NULL"<<" ";
           }
        }
        cout<<"Done"<<endl;
        for(int i=0 ; i<ans.size()-1 ; i++){
            if(ans[i]!=NULL){
                ans[i]->next=ans[i+1];
            }
        }
        
        return root;
    }
};