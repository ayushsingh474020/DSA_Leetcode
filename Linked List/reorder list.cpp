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
    ListNode* middleNode(ListNode* head) {
        int size=1;
        ListNode* p1=head;
        while(p1!=NULL){
            size++;
            p1=p1->next;
        }
        p1=head;
        int count=1;
        if(size%2==0){
            while(count<size/2){
                p1=p1->next;
                count++;
            }
        }
        else{
            while(count<=size/2){
                p1=p1->next;
                count++;
            }
        }
        return p1;
    }
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
    void reorderList(ListNode* head) {
        if(head->next==NULL || head->next->next==NULL){
            return;
        }
        ListNode* e1;
        ListNode* e2;
        ListNode* mid=middleNode(head);
        ListNode* p1=head;
        ListNode* node;
        while(1){
            if(p1->next==mid){
                node=p1;
                break;
            }
            p1=p1->next;
        }
        ListNode* head2=reverseList(mid);
        node->next=head2;
        // p1=head;
        // while(p1!=NULL){
        //     cout<<p1->val;
        //     p1=p1->next;
        // }
        p1=head;
        ListNode* p2=head2;
        while(1){
            e1=p1->next;
            e2=p2->next;
            p1->next=p2;
            if(e1==head2 || e2==NULL){
                break;
            }
            p2->next=e1;
            p1=e1;
            p2=e2;
            
        }
        
    }
};
