class MyQueue {
public:
    stack<int> st; stack<int> gt;
    MyQueue() {}
    void push(int x){
       st.push(x); 
    }
    int pop(){
        while(st.size()!=0){
            gt.push(st.top());
            st.pop();
        }
        int x = gt.top(); gt.pop();
        while(gt.size()!=0){
            st.push(gt.top());
            gt.pop();
        }
        return x;
    }
    int peek(){
        while(st.size()!=0){
            gt.push(st.top());
            st.pop();
        }
        int x = gt.top();
        while(gt.size()!=0){
            st.push(gt.top());
            gt.pop();
        }
        return x;
    }
    bool empty(){
        if(st.size()==0) return true;
        else return false;
    }
};