/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Compare{
    public:
    bool operator()(ListNode* below, ListNode* above)
    {
        if (below->val > above->val) {
            return true;
        }
        return false;
    }
}; 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for(int i=0 ; i<lists.size() ; i++){
            if(lists[i]!=NULL){
                pq.push(lists[i]);
            }
        }
        ListNode* ans=NULL;
        while(!pq.empty()){
            ListNode* tempo;
            ListNode* temp=pq.top();
            // if(temp){
            //     cout<<temp->val<<endl;
            // }
            pq.pop();
            if(temp && temp->next){
                pq.push(temp->next);
            }
            if(ans==NULL){
                ans=temp;
                tempo=ans;
            }
            else{
                tempo->next=temp;
                tempo=tempo->next;
            }
        }
        return ans;
    }
};