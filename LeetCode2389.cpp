class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // sort nums
        sort(nums.begin(),nums.end());
        // make prefix sum array of nums
        for(int i=1; i<nums.size(); i++) nums[i]+=nums[i-1];
        vector<int> ans;
        for(int i=0; i<queries.size(); i++){
            int idx = 0;
            bool flag = false;
            int query = queries[i];
            for(int j=0; j<nums.size(); j++){
                if(nums[j]<=query){
                    flag = true;
                    idx=j;
                }
                else break;
            }
            if(flag==false) ans.push_back(idx);
            else ans.push_back(idx+1);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // sort nums
        sort(nums.begin(),nums.end());
        // make prefix sum array of nums
        for(int i=1; i<nums.size(); i++) nums[i]+=nums[i-1];
        vector<int> ans;
        for(int i=0; i<queries.size(); i++){
            int idx = 0;
            bool flag = false;
            int query = queries[i];
            int lo = 0, hi = nums.size()-1;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(nums[mid]==query){
                    idx=mid;
                    flag=true;
                    break;
                }
                else if(nums[mid]<query) lo = mid+1;
                else hi = mid-1;
            }
            if(flag==false) idx=hi;
            ans.push_back(idx+1);
        }
        return ans;
    }
};