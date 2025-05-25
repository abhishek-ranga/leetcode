class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> m1;
        for(int i=0; i<s.length(); i++) m1[s[i]]++;
        for(int i=0; i<t.length(); i++){
            if(m1.find(t[i])!=m1.end()){
                m1[t[i]]--;
                if(m1[t[i]]==0) m1.erase(t[i]);
            }
            else return false;
        }
        return (m1.size()==0);
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> m1,m2;
        for(int i=0; i<s.length(); i++) m1[s[i]]++;
        for(int i=0; i<t.length(); i++) m2[t[i]]++;
        if(m1.size()!=m2.size()) return false;
        for(auto mp : m1){
            char ch = mp.first;
            int freq = mp.second;
            if(m2.find(ch)!=m2.end()){
                if(m2[ch]!=freq) return false;
            }
            else return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t) return true;
        else return false;
    }
};