class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0; i<digits.size(); i++) m[digits[i]]++;
        for(int i=100; i<1000; i+=2){
            int x=i;
            int a = x%10; x/=10;
            int b = x%10; x/=10;
            int c = x;
            if(m.find(a)!=m.end()){
                m[a]--;
                if(m[a]==0) m.erase(a);
                if(m.find(b)!=m.end()){
                    m[b]--;
                    if(m[b]==0) m.erase(b);
                    if(m.find(c)!=m.end()) ans.push_back(i);
                    m[b]++;
                }
                m[a]++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0; i<digits.size(); i++) m[digits[i]]++;
        for(int i=100; i<1000; i++){
            int num=i;
            if(num%2==0){
                unordered_map<int,int> mp;
                while(num>0){
                    mp[num%10]++;
                    num/=10;
                }
                bool flag = true;
                for(auto ele : mp){
                    if(m.find(ele.first)!=m.end()){
                        if(mp[ele.first]>m[ele.first]) flag=false;
                    }
                    else flag=false;
                }
                if(flag) ans.push_back(i);
            }
        }
        // sort(ans.begin(),ans.end());
        return ans;
    }
};