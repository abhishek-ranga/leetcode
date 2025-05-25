class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        stringstream ss(s);
        string temp;
        while(ss>>temp){
            reverse(temp.begin(),temp.end());
            res+=temp;
            res+=' ';
        }
        res.pop_back();
        return res;
    }
};