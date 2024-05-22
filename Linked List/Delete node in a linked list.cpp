/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* p1=node;
        while(p1!=NULL){
            if(p1->next!=NULL){
                p1->val=p1->next->val;
            }
            if(p1->next->next==NULL){
                p1->next=NULL;
                break;
            }
            p1=p1->next;
        }
    }
};