class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1) return s;
        vector<string> ans(numRows,"");
        int j = 0;
        int dir = -1;
        for(int i=0; i<s.length(); i++){
            if(j==numRows-1 || j==0) dir*=(-1);
            ans[j]+=s[i];
            if(dir==1) j++;
            else j--;
        }
        string res = "";
        for(int i=0; i<numRows; i++){
            res+=ans[i];
        }
        return res;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ans(numRows,"");
        int i = 0;
        int dir = 1;
        while(i<s.length()){
            if(dir==1){
                for(int j=0; j<numRows; j++){
                    ans[j].push_back(s[i]);
                    i++;
                }
                dir = -1;
            }
            if(dir==-1){
                for(int j=numRows-2; j>0; j--){
                    ans[j].push_back(s[i]);
                    i++;
                }
                dir = 1;
            }
        }
        string res = "";
        for(int i=0; i<numRows; i++){
            res+=ans[i];
        }
        return res;
    }
};