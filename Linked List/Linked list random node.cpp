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
    vector<int> nodes;
    Solution(ListNode* head) {
        ListNode* p1=head;
        while(p1!=NULL){
            nodes.push_back(p1->val);
            p1=p1->next;
        }
    }
    
    int getRandom() {
        int i=rand()%(nodes.size());
        return nodes[i];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */