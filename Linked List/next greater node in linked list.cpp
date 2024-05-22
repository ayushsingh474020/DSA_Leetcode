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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* p1=head;
        if(head->next==NULL){
            return head;
        }
        ListNode* p2=head->next;
        if(p2->next==NULL){
            head->next=NULL;
            p2->next=head;
            return p2;
        }
        ListNode* p3=p2->next;
        p1->next=NULL;
        while(p3!=NULL){
            p2->next=p1;
            p1=p2;
            p2=p3;
            p3=p2->next;
        }
        p2->next=p1;
        return p2;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        head=reverseList(head);
        vector<int> ans;
        ans.push_back(0);
        int high=head->val;
        ListNode* p2=head;
        ListNode* p1=head->next;
        while(p1!=NULL){
            if(p1->val>=high){
                ans.push_back(0);
                high=p1->val;
                p2=p1;
                p1=p1->next;
            }
            else{
                if(p2->val>p1->val){
                    ans.push_back(p2->val);
                    p2=p1;
                    p1=p1->next;
                }
                else if(p2->val<=p1->val){
                    // if(ans[ans.size()-1]==p1->val){
                    //     ans.push_back(ans[ans.size()-2]);
                    // }
                    // else{
                    //     ans.push_back(ans[ans.size()-1]);
                    // }
                    int i=0;
                    while(ans[ans.size()-1-i]<=p1->val){
                        i++;
                    }
                    ans.push_back(ans[ans.size()-1-i]);
                    p2=p1;
                    p1=p1->next;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};