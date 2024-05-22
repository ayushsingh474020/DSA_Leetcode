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
    ListNode* removeNodes(ListNode* head) {
        if(head->next==NULL){
            return head;
        }
        else if(head->next->next==NULL){
            if(head->val<head->next->val){
                return head->next;
            }
            else{
                return head;
            }
        }
        head=reverseList(head);
        ListNode* p1=head;
        ListNode* p2=head->next;
        int high=p1->val;
        while(p2!=NULL){
            if(p2->val<high){
                p1->next=p2->next;
                p2=p1->next;
            }
            else if(p2->val>=high){
                high=p2->val;
                p1=p1->next;
                p2=p2->next;
            }
        }
        head=reverseList(head);
        return head;

    }
};