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
        ListNode* newer=new ListNode(101);
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
        while(1){
            if(p1->next->next==NULL){
                p1->next=NULL;
                break;
            }
            p1=p1->next;
        }
        return head;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int size=1;
        ListNode* p1=head;
        while(p1!=NULL){
            size++;
            p1=p1->next;
        }
        ListNode* before;
        ListNode* after;
        int front=1;
        p1=head;
        while(p1!=NULL){
            if(front==k){
                before=p1;
            }
            if(front==size-k){
                after=p1;
                
            }
            p1=p1->next;
            front+=1;
        }
        if(before==after){
            return head;
        }
        head=insertatfirst(head);
        insertatlast(head);
        if(before->next==after || after->next==before){
            p1=head;
            ListNode* extras;
            while(p1!=NULL){
                if(p1->next==before){
                    extras=after->next;
                    p1->next=after;
                    after->next=before;
                    before->next=extras;
                    p1=after;
                    head=deleteatfirst(head);
                    deleteatlast(head);
                    return head;
                }
                if(p1->next==after){
                    extras=before->next;
                    p1->next=before;
                    before->next=after;
                    after->next=extras;
                    p1=before;
                    head=deleteatfirst(head);
                    deleteatlast(head);
                    return head;
                }
                
                p1=p1->next;
                

                
            }
        }
        cout<<before->val<<" "<<after->val; 
        
        p1=head;
        ListNode* extra1;
        ListNode* extra2;
        while(p1!=NULL){
            if(p1->next==before){
                extra1=p1;
            }
            if(p1->next==after){
                extra2=p1;
            }
            p1=p1->next;
        }
        cout<<extra1->val<<" "<<extra2->val;
        ListNode* flag=after->next;
        after->next=before->next;
        before->next=flag;
        flag=extra1->next;
        extra1->next=extra2->next;
        extra2->next=flag;
        head=deleteatfirst(head);
        deleteatlast(head);
        return head;   
    }
};