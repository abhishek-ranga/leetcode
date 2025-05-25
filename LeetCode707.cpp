class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
class MyLinkedList{
public:
    Node* head;
    Node* tail;
    int size;
    MyLinkedList(){
        head = tail = NULL;
        size = 0;
    }
    void addAtTail(int val){
        Node* temp = new Node(val);
        if(size==0){
            head=tail=temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void addAtHead(int val){
        Node* temp = new Node(val);
        if(size==0){
            head=tail=temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void addAtIndex(int idx, int val){
        if(idx<0 || idx>size) return;
        else if(idx==0) addAtHead(val);
        else if(idx==size) addAtTail(val);
        else{
            Node* t = new Node(val);
            Node* temp = head;
            int index = 0;
            while(index!=idx-1){
                temp = temp->next;
                index++;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
        return;
    }
    int get(int idx){
        if(idx<0 || idx>=size) return -1;
        if(idx==0) return head->val;
        if(idx==size-1) return tail->val;
        int index=0;
        Node* temp = head;
        while(index!=idx){
            temp = temp->next;
            index++;
        }
        return temp->val;
    }
    void deleteAtHead(){
        if(size==0) return;
        else if(size==1){
            head = tail = NULL;
            size--;
        } 
        else{
            head = head->next;
            size--;
        }
        return;
    }
    void deleteAtTail(){
        if(size==0) return;
        Node* temp = head;
        while(temp->next!=tail) temp = temp->next;
        temp->next = NULL;
        tail = temp;
        size--;
        return;
    }
    void deleteAtIndex(int idx){
        if(size==0) return;
        if(idx<0 || idx>=size) return;
        if(idx==0) deleteAtHead();
        else if(idx==size-1) deleteAtTail();
        else{
            Node* temp = head;
            int index=0;
            while(index!=idx-1){
                temp = temp->next;
                index++;
            }
            if(temp->next!=tail) temp->next = temp->next->next;
            else temp->next = NULL;
            size--;
        }
        return;
    }
};