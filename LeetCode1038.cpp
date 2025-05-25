class Solution {
public:
    int sum=0;
    void helper(TreeNode* root){
        if(!root) return;
        helper(root->right);
        root->val+=sum;
        sum=root->val;
        helper(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        helper(root);
        return root;
    }
};

class Solution {
public:
    void helper(TreeNode* root, vector<TreeNode*>& v){
        if(!root) return;
        helper(root->left,v);
        v.push_back(root);
        helper(root->right,v);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<TreeNode*> v;
        helper(root,v);
        v.push_back(new TreeNode(0));
        for(int i=v.size()-2; i>=0; i--) v[i]->val+=v[i+1]->val;
        return root;
    }
};