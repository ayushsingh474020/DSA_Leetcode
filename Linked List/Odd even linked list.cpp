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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        int size=0;
        ListNode* p1=head;
        while(p1!=NULL){
            size++;
            p1=p1->next;
        }
        ListNode* p3=head->next;
        ListNode* p4;
        p1=head;
        ListNode* p2=head->next;
        if(size%2==0){
            while(1){
                p1->next=p2->next;
                p4=p1;
                p1=p1->next;
                if(p1==NULL){
                    break;
                }
                p2->next=p1->next;
                p2=p2->next;
                if(p2==NULL){
                    break;
                }
            }
            p4->next=p3;
        }
        else{
            while(1){
                p1->next=p2->next;
                p1=p1->next;
                p2->next=p1->next;
                p2=p2->next;
                if(p2==NULL || p1==NULL){
                    break;
                }
            }
            p1->next=p3;
        }
        return head;
        
        
    }
};