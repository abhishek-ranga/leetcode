class Solution {
public:
    bool isVowel(char ch){
        if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') return true;
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
        return false;
    }
    string sortVowels(string s) {
        vector<char> vowels;
        for(int i=0; i<s.length(); i++){
            if(isVowel(s[i])){
                vowels.push_back(s[i]);
                s[i]=0;
            }
        }
        sort(vowels.begin(),vowels.end());
        int v=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]==0) s[i] = vowels[v++];
        }
        return s;
    }
};