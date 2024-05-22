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
    bool hasCycle(ListNode *head) {
        int no=pow(10,4)+1;
        int size=0;
        ListNode* p1=head;
        while(p1!=NULL){
            size++;
            if(size>=no){
                return true;
            }
            p1=p1->next;
        }
        return false;

    }
};