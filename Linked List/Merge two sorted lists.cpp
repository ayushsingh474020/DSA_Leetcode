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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1=list1;
        ListNode* p2=list2;
        ListNode* ans=new ListNode();
        ListNode* ptr=ans;
        while(p1!=NULL && p2!=NULL){
            if(p1->val>=p2->val){
                ptr->next=p2;
                ptr=p2;
                p2=p2->next;
            }
            else{
                ptr->next=p1;
                ptr=p1;
                p1=p1->next;
            }
        }
        while(p1!=NULL){
            ptr->next=p1;
            ptr=p1;
            p1=p1->next;
        }
        while(p2!=NULL){
            ptr->next=p2;
            ptr=p2;
            p2=p2->next;
        }
        return ans->next;
        
    }
};