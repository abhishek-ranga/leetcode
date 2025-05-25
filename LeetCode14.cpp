class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs[strs.size()-1];
        string res = "";
        for(int i=0;i<strs[0].length();i++){
            if(first[i]!=last[i]) break;
            else res+=first[i];
        }
        return res;
    }
};