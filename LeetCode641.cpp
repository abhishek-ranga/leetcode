class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class MyCircularDeque {
public:
    Node* head;
    Node* tail;
    int s; // current size;
    int c; // capacity
    MyCircularDeque(int k) {
        head = NULL; tail = NULL;
        s = 0; c = k;
    }
    bool insertFront(int val) {
        if(s==c) return false;
        else if(s==0){
            Node* temp = new Node(val);
            head = temp;
            tail = temp;
        }
        else if(s<c){
            Node* t = new Node(val);
            t->next = head;
            head->prev = t;
            head = head->prev;
        }
        s++;
        return true;
    }
    bool insertLast(int val) {
        if(s==c) return false;
        else if(s==0){
            Node* temp = new Node(val);
            head = temp;
            tail = temp;
        }
        else if(s<c){
            Node* t = new Node(val);
            tail->next = t;
            t->prev = tail;
            tail = tail->next;
        }
        s++;
        return true;
    }
    bool deleteFront() {
        if(s==0) return false;
        else if(s==1) head = tail = NULL;
        else{
            head = head->next;
            head->prev = NULL;
        }
        s--;
        return true;
    }
    bool deleteLast() {
        if(s==0) return false;
        else if(s==1) head = tail = NULL;
        else{
            tail = tail->prev;
            tail->next = NULL;
        }
        s--;
        return true;
    }
    int getFront() {
        if(head!=NULL) return head->val;
        else return -1;
    }
    int getRear() {
        if(tail!=NULL) return tail->val;
        return -1;
    }
    bool isEmpty() {
        if(head==NULL && tail==NULL) return true;
        else return false;
    }
    bool isFull() {
        if(s==c) return true;
        else return false;
    }
};


class MyCircularDeque {
public:
    vector<int> a;
    int front=-1, rear=-1;
    int curr=0; int size;
    MyCircularDeque(int k){
        a.resize(k);
        size=k;
    }
    bool insertFront(int value) {
        if(isFull()) return false;
        if(front==-1 && rear==-1){
            front=rear=0;
            a[front] = value;
        }
        else if(front==0){
            front = size-1;
            a[front] = value;
        }
        else{
            front = front-1;
            a[front] = value;
        }
        curr++;
        return true;
    }
    bool insertLast(int value) {
        if(isFull()) return false;
        if(front==-1 && rear==-1){
            front=rear=0;
            a[rear] = value;
        }
        else if(rear==size-1){
            rear = 0;
            a[rear] = value;
        }
        else{
            rear = rear+1;
            a[rear] = value;
        }
        curr++;
        return true;
    }
    bool deleteFront() {
        if(isEmpty()) return false;
        if(front==size-1) front=0;
        else{
            front = front+1;
        }
        curr--;
        return true;
    }
    bool deleteLast() {
        if(isEmpty()) return false;
        if(rear==0) rear=size-1;
        else{
            rear = rear-1;
        }
        curr--;
        return true;
    }
    int getFront() {
        if(isEmpty()) return -1;
        else return a[front];
    }
    int getRear() {
        if(isEmpty()) return -1;
        else return a[rear];
    }
    bool isEmpty() {
        return (curr==0);
    }
    bool isFull() {
        return (curr==size);
    }
};