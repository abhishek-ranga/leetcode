class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int vowel=0, mx=0;
        for(int i=0; i<k; i++){
            if(isVowel(s[i])) vowel++;
        }
        mx = max(mx,vowel);
        int i=1,j=k,n=s.length();
        while(j<n){
            if(isVowel(s[j])) vowel++;
            if(isVowel(s[i-1])) vowel--;
            mx=max(mx,vowel);
            i++; j++;
        }
        return mx;
    }
};