/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* p=head;
        Node* head2=new Node(10);
        Node* extra=head2;
        unordered_map<Node*,Node*> m;
        while(p!=NULL){
            Node* newer=new Node(p->val);
            m[p]=newer;
            newer->random=NULL;
            extra->next=newer;
            extra=newer;
            p=p->next;
        }
        extra->next=NULL;
        head2=head2->next;
        p=head;
        extra=head2;
        while(p!=NULL){
            extra->random=m[p->random];
            extra=extra->next;
            p=p->next;
        }
        return head2;
        
    }
};