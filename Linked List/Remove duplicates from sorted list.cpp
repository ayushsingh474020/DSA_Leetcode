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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* p1=head;
        ListNode* p2=head->next;
        while(p2!=NULL){
            if(p1->val==p2->val){
                // if(p2->next=NULL){
                //     p1->next=NULL;
                //     break;
                // }
                // else{
                    p2=p2->next;
                    if(p2==NULL){
                        p1->next=p2;
                    }
                // }
            }
            else{
                p1->next=p2;
                p1=p2;
                p2=p2->next;
            }
        }
        return head;
    }
};