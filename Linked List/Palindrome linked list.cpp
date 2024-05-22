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
    bool compare(ListNode* head1, ListNode* head2){
        ListNode* p1=head1;
        ListNode* p2=head2;
        while(p1!=NULL && p2!=NULL){
            if(p1->val!=p2->val){
                return false;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head,ListNode* end) {
        ListNode* p1=head;
        ListNode* p2=head->next;
        ListNode* p3=p2->next;
        p1->next=NULL;
        while(p3!=end){
            p2->next=p1;
            p1=p2;
            p2=p3;
            p3=p2->next;
        }
        p2->next=p1;
        return p2;
    }
    bool isPalindrome(ListNode* head) {
        int size=0;
        ListNode* p1=head;
        while(p1!=NULL){
            size++;
            p1=p1->next;
        }
        if(size==1){
            return true;
        }
        if(size==2){
            if(head->val==head->next->val){
                return true;
            }
            else{
                return false;
            }
        }
        ListNode* pmid=new ListNode();
        p1=head;
        int count;
        if(size%2==0){
            count=(size/2)-1;
        }
        else{
            count=size/2;
        }
        while(count--){
            p1=p1->next;
        }
        if(size%2==0){
            pmid->val=p1->next->val;
            pmid->next=p1->next->next;
        }
        else{
            pmid->val=p1->val;
            pmid->next=p1->next;
        }
        ListNode* extra;
        ListNode* extras=p1->next;
        extra=reverseList(head,extras);
        return compare(extra,pmid);
        
        
        
    }
};