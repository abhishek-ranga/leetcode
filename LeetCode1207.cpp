class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m; unordered_set<int> s;
        for(int i=0; i<arr.size(); i++) m[arr[i]]++;
        for(auto mp : m){
            if(s.find(mp.second)!=s.end()) return false;
            else s.insert(mp.second);
        }
        return true;
    }
};