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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count=0;
        ListNode* p1=list1;
        ListNode* p2;
        ListNode* p3;
        while(p1!=NULL){
            if(count==a-1){
                p2=p1;
            }
            if(count==b+1){
                p3=p1;
            }
            p1=p1->next;
            count++;
            // if(a==b){
            //     if(count==a-1){
            //         p2=p1;
            //         p3=p1->next->next;
            //         break;
            //     }
            // }
        }
        cout<<p2->val<<" "<<p3->val;
        p2->next=list2;
        p1=list2;
        while(1){
            if(p1->next==NULL){
                p1->next=p3;
                break;
            }
            p1=p1->next;
        }
        return list1;
    }
};