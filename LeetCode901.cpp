class StockSpanner {
public:
    stack<vector<int>> st;
    StockSpanner() {}
    int next(int price) {
        int span=1;
        while(!st.empty() && st.top()[0]<=price){
            span+=st.top()[1];
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};

class StockSpanner {
public:
    stack<int> st; stack<int> helper;
    StockSpanner() {}
    int next(int price) {
        st.push(price); int count=0;
        while(!st.empty() && st.top()<=price){
            helper.push(st.top());
            st.pop();
            count++;
        }
        while(helper.size()!=0){
            st.push(helper.top());
            helper.pop();
        }
        return count;
    }
};