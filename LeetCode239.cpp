class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(); vector<int> ans;
        // if(k==1) return nums;
        // brute force
        // for(int i=0; i<n-k+1; i++){
        //     int mx = INT_MIN;
        //     for(int j=i; j<i+k; j++){
        //         mx = max(mx,nums[j]);
        //     }
        //     ans.push_back(mx);
        // }
        vector<int> ngi(n); stack<int> st;
        ngi[n-1]=n; st.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(st.size()!=0 && nums[st.top()]<=nums[i]) st.pop();
            if(st.size()==0) ngi[i] = n;
            else ngi[i] = st.top();
            st.push(i);
        }
        int j=0;
        for(int i=0; i<n-k+1; i++){
            if(j<i) j=i;
            int mx = nums[i]; // starting of window
            while(j<i+k){
                mx = nums[j];
                if(ngi[j]>=i+k) break;
                j = ngi[j];
            }
            ans.push_back(mx);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1) return nums;
        deque<int> dq; // monotonic decreasing deque
        vector<int> ans; //(n-k+1) // i should be at least = k-1
        for(int i=0; i<nums.size(); i++){
            while(dq.size()!=0 && nums[i]>nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            int j = i-k+1; // start of the window;
            while(dq.front()<j) dq.pop_front();
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};