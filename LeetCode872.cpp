class Solution {
public:
    void preOrder(TreeNode* root, vector<int>& v) {
        if(!root) return;
        if(!root->left&&!root->right) v.push_back(root->val);
        preOrder(root->left,v);
        preOrder(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        preOrder(root1,v1);
        preOrder(root2,v2);
        if(v1.size()!=v2.size()) return false;
        for(int i=0; i<v1.size(); i++){
            if(v1[i]!=v2[i]) return false;
        }
        return true;
    }
};

class Solution {
public:
    void preOrder(TreeNode* root, string& t) {
        if(!root) return;
        if(!root->left&&!root->right) t+=to_string(root->val)+"#";
        preOrder(root->left,t);
        preOrder(root->right,t);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1,s2;
        preOrder(root1,s1);
        preOrder(root2,s2);
        return s1==s2;
    }
};