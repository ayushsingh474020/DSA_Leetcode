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
    ListNode* insertatfirst(ListNode* head){
        ListNode* newer=new ListNode(-1);
        newer->next=head;
        return newer;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        for(int i=0 ; i<1 ; i++){
            head=insertatfirst(head);
        }
        int k=n+1;
        ListNode* fast=head;
        ListNode* slow=head;
        while(k--){
            fast=fast->next;
        }
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        for(int i=0 ; i<1 ; i++){
            head=head->next;
        }
        return head;
    }
};