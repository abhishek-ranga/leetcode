class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        reverse(s.begin(),s.end());
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