class Solution {
public:
    string reversePrefix(string word, char ch) {
        int lo = 0;
        int hi = -1;
        for(int i=0; i<word.length(); i++){
            if(word[i]==ch){
                hi = i;
                break;
            }
        }
        while(lo<=hi){
            swap(word[lo++],word[hi--]);
        }
        return word;
    }
};