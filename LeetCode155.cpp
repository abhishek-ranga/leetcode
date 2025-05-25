class MinStack{ // goat
public:
    stack<long long> st; long long mn;
    MinStack(){
        mn = LLONG_MAX;
    }
    void push(long long val){
        if(st.size()==0){
            st.push(val);
            mn = val;
        }
        else if(val>=mn) st.push(val);
        else{ // val<min
            st.push(2*val-mn);
            mn = val;
        }
    }
    void pop(){
        if(st.top()<mn){
            // st.top()<mn : a dummy value is present
            // before popping the top element retrieve the old min
            long oldmin = 2*mn - st.top();
            mn = oldmin;
        }
        st.pop();
    }
    int top(){
        if(st.top()<mn) return mn;
        else return st.top();
    }
    int getMin(){return mn;}
};

class MinStack{ // using an extra stack O(1) for every operation, sc : O(n)
public:
    stack<int> st; stack<int> helper;
    MinStack(){}
    void push(int val){
        st.push(val);
        if(helper.size()==0 || val<helper.top()) helper.push(val);
        else helper.push(helper.top());
    }
    void pop(){
        st.pop();
        helper.pop();
    }
    int top(){return st.top();}
    int getMin(){return helper.top();}
};

// vector implementation of stack
class MinStack{ // sc : O(1);
public:
    vector<int> stack;
    MinStack(){}
    void push(int val){
        stack.push_back(val);
    }
    void pop(){
        stack.pop_back();
    }
    int top(){
        return stack[stack.size()-1];
    }
    int getMin(){ // O(n);
        int mn = INT_MAX;
        for(int i=0; i<stack.size(); i++){
            mn = min(mn,stack[i]);
        }
        return mn;
    }
};

class MinStack{ // O(n) for every getMin operation, sc : O(n)
public:
    stack<int> st;
    MinStack(){} // constructor
    void push(int val){ // O(1)
        st.push(val);
    }
    void pop(){ // O(1)
        st.pop();
    }
    int top(){ // O(1)
        return st.top();
    }
    int getMin(){
        stack<int> helper; int mn = INT_MAX;
        while(st.size()!=0){
            mn = min(mn,st.top());
            helper.push(st.top());
            st.pop();
        }
        while(helper.size()!=0){
            st.push(helper.top());
            helper.pop();
        }
        return mn;
    }
};