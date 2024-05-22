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
        ListNode* newer=new ListNode(-101);
        newer->next=head;
        return newer;
    }
    void insertatlast(ListNode* head){
        ListNode* newer=new ListNode(101);
        ListNode* p1=head;
        while(1){
            if(p1->next==NULL){
                p1->next=newer;
                break;
            }
            p1=p1->next;
        }
    }
    ListNode* deleteatfirst(ListNode* head){
        return head->next;
    }
    ListNode* deleteatlast(ListNode* head){
        ListNode* p1=head;
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        while(p1->next->next!=NULL){
            p1=p1->next;
        }
        p1->next=NULL;
        return head;
    }
    ListNode* partition(ListNode* head, int x) {
        if(x>100 || x<-100){
            return head;
        }
        if(head==NULL || head->next==NULL){
            return head;
        }
        head=insertatfirst(head);
        insertatlast(head);
        ListNode* pextra=head;
        ListNode* head1=head;
        ListNode* head2;
        while(pextra!=NULL){
            if (pextra->val>=x){
                head2=pextra;
                break;
            }
            pextra=pextra->next;
        }
        cout<<head1->val<<" "<<head2->val;
        // head1->next=NULL;
        
        ListNode* p1=head1;
        ListNode* p2=head2;
        ListNode* p3=head1->next;
        cout<<p3->val;
        while(p3!=NULL){
            if(p3==p2){
                p3=p3->next;
            }
            else if(p3->val<x){
                p1->next=p3;
                p1=p3;
                p3=p3->next;
                p1->next=NULL;
            }
            else{
                p2->next=p3;
                p2=p3;
                p3=p3->next;
                p2->next=NULL;
            }
        }
        
        head1=deleteatfirst(head1);
        head2=deleteatlast(head2);
        // if(head1==NULL){
        //     return head2;
        // }
        p3=head1;
        while(1){
            if(p3==head2){
                return head2;
            }
            if(p3->next==NULL){
                p3->next=head2;
                break;
            }
            p3=p3->next;
        }
        return head1;
    }
};