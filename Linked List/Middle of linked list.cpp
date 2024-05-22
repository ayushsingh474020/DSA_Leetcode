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
};