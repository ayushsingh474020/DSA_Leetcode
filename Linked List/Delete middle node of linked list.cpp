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
    ListNode* deleteMiddle(ListNode* head) {
        int size=0;
        ListNode* p1=head;
        while(p1!=NULL){
            p1=p1->next;
            size++;
        }
        if(size==1){
            return NULL;
        }
        if(size==2){
            head->next=NULL;
            return head;
        }
        p1=head;
        int count=0;
        while(p1!=NULL){
            if(count==(size/2)-1){
                break;
            }
            count++;
            p1=p1->next;
        }
        p1->next=p1->next->next;
        return head;
    }
};