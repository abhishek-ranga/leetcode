class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;
        for(string str : strs){
            string lexo = str;
            sort(lexo.begin(),lexo.end());
            if(m.find(lexo)==m.end()){
                vector<string> v;
                v.push_back(str);
                m[lexo] = v;
            }
            else{
                m[lexo].push_back(str);
            }
        }
        for(auto x : m){
            ans.push_back(x.second);
        }
        return ans;
    }
};