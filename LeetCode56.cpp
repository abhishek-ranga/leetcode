bool cmp(vector<int> &a, vector<int> &b){
    return a[1]<b[1];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> result; int n = intervals.size();
        result.push_back(intervals[n-1]);
        for(int i=n-2; i>=0; i--){
            vector<int> &lastInterval = result[result.size()-1]; // last included interval
            vector<int> curr = intervals[i];
            if(curr[1]>=lastInterval[0]){ // curr.end >= last.start -> overlapping
                lastInterval[0] = min(lastInterval[0],curr[0]);
                lastInterval[1] = max(lastInterval[1],curr[1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

bool cmp(vector<int> &a, vector<int> &b){
    return a[0]<b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> result; int n = intervals.size();
        result.push_back(intervals[0]);
        for(int i=1; i<n; i++){
            vector<int> &lastInterval = result[result.size()-1];
            vector<int> curr = intervals[i];
            if(curr[0]<=lastInterval[1]){
                lastInterval[0] = min(lastInterval[0],curr[0]);
                lastInterval[1] = max(lastInterval[1],curr[1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};