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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* p1=l1;
        ListNode* p2=l2;
        ListNode* head=new ListNode();
        ListNode* extra=head;
        while(p1!=NULL && p2!=NULL){
            int a=p1->val+p2->val+carry;
            ListNode* newer=new ListNode(a%10);
            extra->next=newer;
            extra=extra->next;
            carry=a/10;
            p1=p1->next;
            p2=p2->next;
        }
        while(p1!=NULL){
            int a=p1->val+carry;
            ListNode* newer=new ListNode(a%10);
            extra->next=newer;
            extra=extra->next;
            carry=a/10;
            p1=p1->next;
        }
        while(p2!=NULL){
            int a=p2->val+carry;
            ListNode* newer=new ListNode(a%10);
            extra->next=newer;
            extra=extra->next;
            carry=a/10;
            p2=p2->next;
        }
        if (carry!=0){
            ListNode* newer=new ListNode(carry);
            extra->next=newer;
        }
        head=head->next;
        return head;
        
    }
};