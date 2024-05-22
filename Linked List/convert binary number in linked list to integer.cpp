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
    int getDecimalValue(ListNode* head) {
        int size=0;
        ListNode* p1=head;
        while(p1!=NULL){
            size++;
            p1=p1->next;
        }
        int ans=0;
        p1=head;
        while(p1!=NULL){
            ans+=(p1->val)*pow(2,size-1);
            size--;
            p1=p1->next;
        }
        return ans;
    }
};