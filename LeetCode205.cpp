class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int> v(150,1000);
        // from pov of s
        for(int i=0;i<s.size();i++){
            int idx = (int)s[i];
            if(v[idx]==1000) v[idx] = s[i] - t[i];
            else if(v[idx]!=(s[i]-t[i])) return false;
        }
        // resetting the vector
        for(int i=0;i<150;i++) v[i]=1000;
        // from pov of t
        for(int i=0;i<t.size();i++){
            int idx = (int)t[i];
            if(v[idx]==1000) v[idx] = t[i] - s[i];
            else if(v[idx]!=(t[i]-s[i])) return false;
        }
        return true;
    }
};