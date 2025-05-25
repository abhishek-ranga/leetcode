class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_set<int> s1, s2;
        for(int ele : nums1) s1.insert(ele);
        for(int ele : nums2) s2.insert(ele);
        for(int n1 : s1) if(s2.find(n1)==s2.end()) ans[0].push_back(n1);
        for(int n2 : s2) if(s1.find(n2)==s1.end()) ans[1].push_back(n2);
        return ans;
    }
};