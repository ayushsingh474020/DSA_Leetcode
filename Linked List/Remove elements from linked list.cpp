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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return head;
        }
        else{
            while(head->val==val){
                if(head->next==NULL){
                    break;
                }
                head=head->next;
            }
        }
        if(head->val==val && head->next==NULL){
            head=head->next;
        }
        if(head==NULL){
            return head;
        }
        ListNode* p2=head;
        while(p2!=NULL){
            if(p2->next!=NULL){
                if(p2->next->val==val){
                    p2->next=p2->next->next;
                }
                else{
                    p2=p2->next;
                }
            }
            else{
                break;
            }
            // p2=p2->next;
        }
        return head;
    }
};