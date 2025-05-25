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
        // step 1 - create a deep copy without random pointer
        Node* dummy = new Node(-1); Node* temp = head; Node* tempC = dummy;
        while(temp){
            Node* a = new Node(temp->val);
            tempC->next = a;
            tempC = tempC->next;
            temp = temp->next;
        }
        Node* a = head;
        Node* b = dummy->next;
        // step 2 - map the original node with duplicate nodes
        unordered_map<Node*,Node*> m;
        Node* t1=a; Node* t2=b;
        while(t1){
            m[t1] = t2;
            t1 = t1->next;
            t2 = t2->next;
        }
        for(auto x : m){
            Node* org = x.first;
            Node* dupe = x.second;
            if(org->random){
                Node* orgrandom = org->random;
                Node* duperandom = m[org->random];
                dupe->random = duperandom;
            }
        }
        return b;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // step 1 - create a deep copy without random pointer
        Node* dummy = new Node(-1); Node* temp = head; Node* tempC = dummy;
        while(temp){
            Node* a = new Node(temp->val);
            tempC->next = a;
            tempC = tempC->next;
            temp = temp->next;
        }
        Node* duplicate = dummy->next;
        // step 2 - alternate connections
        Node* a = head; Node* b = duplicate; 
        dummy = new Node(-1); Node* tempD = dummy;
        while(a){
            tempD->next = a;
            a = a->next;
            tempD = tempD->next;
            tempD->next = b;
            b = b->next;
            tempD = tempD->next;
        }
        dummy = dummy->next;
        // step 3 - making random connections in duplicate list
        Node* t1 = dummy; // t1 will traverse in the original list
        Node* t2;
        while(t1){
            t2 = t1->next; // t2 is for duplicate list
            if(t1->random!=NULL) t2->random = t1->random->next;
            t1 = t1->next->next;
        }
        // step 4 - removing the connections / separating the lists;
        Node* d1 = new Node(-1); Node* d2 = new Node(-1);
        Node* t = dummy; Node *temp1 = d1, *temp2 = d2;
        while(t){
            temp1->next = t;
            t = t->next;
            temp1 = temp1->next;
            temp2->next = t;
            t = t->next;
            temp2 = temp2->next;
        }
        temp1->next = NULL; temp2->next = NULL;
        d1 = d1->next; // original with random;
        d2 = d2->next; // duplicate with random;
        return d2;
    }
};