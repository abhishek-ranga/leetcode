class MyStack {
public:
    queue<int> q;
    int size;
    MyStack(){size=0;}
    void push(int x){
        q.push(x);
        size++;
    }
    int pop(){
        for(int i=1; i<size; i++){
            q.push(q.front());
            q.pop();
        } 
        int x = q.front(); q.pop(); size--;
        return x;
    }
    int top(){
        // for(int i=1; i<size; i++){
        //     q.push(q.front());
        //     q.pop();
        // }
        // int x = q.front();
        // q.push(q.front()); q.pop();
        // return x;
        return q.back();
    }
    bool empty(){
        // if(q.size()==0) return true;
        // else return false;
        if(q.empty()) return true;
        else return false;
    }
};