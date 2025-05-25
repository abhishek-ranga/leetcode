class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> afterDiscount(prices.size()); stack<int> st;
        for(int i=prices.size()-1; i>=0; i--){
            while(st.size()!=0 && st.top()>prices[i]) st.pop();
            if(st.size()==0) afterDiscount[i]=prices[i];
            else afterDiscount[i] = prices[i]-st.top();
            st.push(prices[i]);
        }
        return afterDiscount;
    }
};