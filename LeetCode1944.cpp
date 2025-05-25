class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size(); vector<int> ans(n,0);
        // brute force
        // for(int i=0; i<n-1; i++){
        //     int mx = INT_MIN;
        //     for(int j=i+1; j<n; j++){
        //         if(min(heights[i],heights[j])>mx) ans[i]++;
        //         mx = max(mx,heights[j]);
        //     }
        // }
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            int count=0;
            while(st.size()!=0 && heights[i]>st.top()){
                st.pop();
                count++;
            }
            if(st.size()!=0) count++;
            ans[i] = count;
            st.push(heights[i]);
        }
        return ans;
    }
};