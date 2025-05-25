class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size()); stack<int> st; int n = nums.size();
        for(int i=n*2-1; i>=0; i--){
            while(st.size()!=0 && st.top()<=nums[i%n]) st.pop();
            if(st.size()==0) ans[i%n]=-1;
            else ans[i%n] = st.top();
            st.push(nums[i%n]);
        }
        return ans;
    }
};