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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int size=0;
        ListNode* p1=head;
        while(p1!=NULL){
            size++;
            p1=p1->next;
        }
        p1=head;
        if(size<=k){
            k=k%size;
        }
        while(size-k>1){
            p1=p1->next;
            k++;
        }
        ListNode* splithead=p1->next;
        p1->next=NULL;
        ListNode* p2=splithead;
        if(p2==NULL){
            return head;
        }
        while(p2->next!=NULL){
            p2=p2->next;
        }
        p2->next=head;
        return splithead;
    }
};