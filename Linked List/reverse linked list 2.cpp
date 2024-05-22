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
        ListNode* newer=new ListNode(-501);
        newer->next=head;
        return newer;
    }
    void insertatlast(ListNode* head){
        ListNode* newer=new ListNode(501);
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
        while(1){
            if(p1->next->next==NULL){
                p1->next=NULL;
                break;
            }
            p1=p1->next;
        }
        return head;
    }
    ListNode* reverseList(ListNode* head,ListNode* end, ListNode* lleft, ListNode* rright) {
        ListNode* p1=head;
        ListNode* p2=head->next;
        ListNode* p3=p2->next;
        p1->next=rright;
        while(p3!=rright){
            p2->next=p1;
            p1=p2;
            p2=p3;
            p3=p2->next;
        }
        p2->next=p1;
        return p2;
    }   
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next==NULL){
            return head;
        }
        if(left==right){
            return head;
        }
        head=insertatfirst(head);
        insertatlast(head);
        ListNode* lleft;
        ListNode* lefty;
        ListNode* rright;
        ListNode* righty;
        ListNode* p1=head;
        int pos=0;
        while(p1!=NULL){
            if(pos==left-1){
                lleft=p1;
            }
            if(pos==left){
                lefty=p1;
            }
            if(pos==right){
                righty=p1;
            }
            if(pos==right+1){
                rright=p1;
            }
            p1=p1->next;
            pos++;
        }
        ListNode* p2;
        p2=reverseList(lefty,righty,lleft,rright);
        lleft->next=p2;
        head=deleteatfirst(head);
        deleteatlast(head);
        return head;


    }
};