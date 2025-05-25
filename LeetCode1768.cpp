// two pointer
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int n = word1.length();
        int m = word2.length();
        int i = 0;
        int j = 0;
        while(i<n && j<m){
            res+=word1[i];
            i++;
            res+=word2[j];
            j++;
        }
        if(i==n) res+=word2.substr(j);
        if(j==m) res+=word1.substr(i);
        return res;
    }
};

// one pointer
// string mergeAlternately(string w1, string w2) {
//     string res = "";
//     for (int i = 0; i < w1.size() || i < w2.size(); ++i) {
//         if (i < w1.size()) res.push_back(w1[i]);
//         if (i < w2.size()) res.push_back(w2[i]);
//     }
//     return res;
// };