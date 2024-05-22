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
    ListNode* traversal(ListNode* head,int n){
        while(n>1){
            head=head->next;
            n--;
        }
        ListNode* ans=head->next;
        head->next=NULL;
        return ans;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size=0;
        ListNode* p1=head;
        while(p1!=NULL){
            size++;
            p1=p1->next;
        }
        int a=size/k;
        int b=size%k;
        int c=a;
        vector<ListNode*> ans;
        ListNode* universal=head;
        while(b--){
            ans.push_back(universal);
            universal=traversal(universal,a+1);
        }
        c=ans.size();
        while((k-c)>0){
            ans.push_back(universal);
            c++;
            if(universal!=NULL){
                universal=traversal(universal,a);
            }
            
        }
        return ans;
    }
};