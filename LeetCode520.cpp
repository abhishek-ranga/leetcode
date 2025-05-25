class Solution {
public:
    bool detectCapitalUse(string word) {
        int small=0, capital=0;
        for(int i=0; i<word.length(); i++){
            if(word[i]>=65 && word[i]<=90) capital++;
            if(word[i]>=97 && word[i]<=122) small++;
        }
        if(word.length()==capital) return true;
        if(word.length()==small) return true;
        if(capital==1 && word[0]>=65 && word[0]<=90) return true;
        return false;
    }
};