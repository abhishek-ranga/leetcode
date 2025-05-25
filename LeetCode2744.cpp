class Solution { // O(n) single loop
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s; int count=0;
        for(int i=0; i<words.size(); i++){
            string str = words[i]; reverse(str.begin(),str.end());
            if(s.find(str)!=s.end()) count++;
            else s.insert(words[i]);
        }
        return count;
    }
};

class Solution { // O(n) 2 loops
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s; int count=0;
        for(int i=0; i<words.size(); i++) s.insert(words[i]);
        for(int i=0; i<words.size(); i++){
            s.erase(words[i]);
            string ss = words[i]; reverse(ss.begin(),ss.end());
            if(s.find(ss)!=s.end()) count++;
        }
        return count;
    }
};

class Solution { // O(n^2)
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int count=0, n=words.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(words[i][0]==words[j][1]&&words[i][1]==words[j][0]) count++;
            }
        }
        return count;
    }
};