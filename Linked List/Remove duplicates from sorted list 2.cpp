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
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        while(p1->next->next!=NULL){
            p1=p1->next;
        }
        p1->next=NULL;
        return head;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        int flag=0;
        if(head==NULL || head->next==NULL){
            return head;
        }
        if(head->next->next==NULL){
            if(head->val==head->next->val){
                return NULL;
            }
            else{
                return head;
            }
        }
        head=insertatfirst(head);
        insertatlast(head);
        ListNode* p1=head;
        ListNode* p2=head->next;
        ListNode* p3=p2->next;
        while(p3!=NULL){
            if(p2->val==p3->val){
                p3=p3->next;
                flag=1;
            }
            else{
                if (flag==0){
                    p1=p1->next;
                    p2=p2->next;
                    p3=p3->next;
                }
                if(flag==1){
                    p1->next=p3;
                    p2=p3;
                    p3=p3->next;
                    flag=0;
                }
                 
            }
        }
        head=deleteatfirst(head);
        head=deleteatlast(head);
        return head;
    }
};