class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        // ngi
        stack<int> st; vector<int> ngi(arr.size()); int n = arr.size();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            if(st.empty()) ngi[i]=i;
            else ngi[i] = st.top();
            st.push(i);
        }
        for(int i=0; i<n; i++){
            ngi[i] = ngi[i]-i;
        }
        return ngi;
    }
};