class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()) return false;
        unordered_map<char,int> m1,m2;
        for(int i=0; i<word1.length(); i++) m1[word1[i]]++;
        for(int i=0; i<word2.length(); i++) m2[word2[i]]++;
        if(m1.size()!=m2.size()) return false;
        for(auto x : m1){
            if(m2.find(x.first)==m2.end()) return false;
        }
        unordered_map<int,int> p1,p2;
        for(auto x : m1) p1[x.second]++;
        for(auto y : m2) p2[y.second]++;
        if(p1.size()!=p2.size()) return false;
        for(auto z : p1){
            if(z.second!=p2[z.first]) return false;
        }
        return true;
    }
};