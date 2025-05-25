class Solution {
public:
    string sortSentence(string str) {
        vector<string> store(10);
        stringstream ss(str);
        string temp;
        while(ss>>temp){
            int n = std::stoi(temp.substr(temp.length()-1,1));
            store[n] = temp.substr(0,temp.length()-1);
        }
        string res = "";
        for(auto s : store){
            res += s;
            res += " ";
        }
        int j = res.length()-1;
        while(res[j]==' '){
            res.pop_back();
            j--;
        }
        res.erase(0,1);
        return res;
    }
};

class Solution {
public:
    string sortSentence(string s) {
        int n=s.size();
        vector<string> pos(10);
        string temp;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){temp+=s[i];}
            
            else {int b=temp[temp.size()-1]-'0';
            temp.pop_back();
            pos[b]=temp;
            temp="";
            count++;}
            
        }
        if (!temp.empty()) {
        int b = temp.back() - '0';
        temp.pop_back();
        pos[b] = temp;
        count++;
    }
        string ans;
        for(int i=1;i<=count;i++){
            ans+=pos[i];
            ans+=' ';
            
        }
        ans.pop_back();
        return ans;
    }
};