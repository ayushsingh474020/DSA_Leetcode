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
    int pairSum(ListNode* head) {
        int size=0;
        ListNode* p1=head;
        while(p1!=NULL){
            p1=p1->next;
            size++;
        }
        cout<<size;
        p1=head;
        int count=0;
        while(p1!=NULL){
            if(count==(size/2)-1){
                break;
            }
            count++;
            p1=p1->next;
        }
        
        
        ListNode* newhead=p1->next;
        p1->next=NULL;
        p1=head;
        newhead=reverseList(newhead);
        ListNode* p2=newhead;
        int ans=0;
        while(p1!=NULL && p2!=NULL){
            if(p1->val + p2->val >ans){
                ans=p1->val + p2->val;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return ans;
    }
};