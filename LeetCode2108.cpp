class Solution {
public:
    string rev(string str){
        reverse(str.begin(),str.end());
        return str;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(words[i]==rev(words[i])) return words[i];
        }
        return "";
    }
};

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            string rev = words[i];
            reverse(rev.begin(),rev.end());
            if(words[i]==rev) return words[i];
        }
        return "";
    }
};